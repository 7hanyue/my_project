#include "ModbusTcpDriver.h"
#include <qDebug>
ModbusTcpDriver::ModbusTcpDriver()
{
	//把 m_regReadBuffer 数组的每一个字节都设置为 0 ，实现数组初始化清零
	memset(m_regReadBuffer, 0, sizeof(m_regReadBuffer));
}
ModbusTcpDriver::~ModbusTcpDriver()
{

}

bool ModbusTcpDriver::Connect(const std::string& ip, int port, int slave)
{
	m_ctx = modbus_new_tcp(ip.c_str(), port);
	if (!m_ctx)
	{
		qDebug() << "new_tcp failed!:" << modbus_strerror(errno);
		return false;
	}
	//设置字节超时时间 第二个参数是：秒 第三个参数是：微秒
	modbus_set_byte_timeout(m_ctx, 0, 200000);
	//设置响应超时时间 第二个参数是：秒 第三个参数是：微秒
	modbus_set_response_timeout(m_ctx, 0, 200000);

	modbus_set_debug(m_ctx, false);

	modbus_set_slave(m_ctx, slave);

	if (modbus_connect(m_ctx) == -1)
	{
		qDebug() << "connect failed!:" << modbus_strerror(errno);
		modbus_free(m_ctx);
		m_ctx = nullptr;
		return false;
	}

	return true;
}

bool ModbusTcpDriver::DisConnect()
{
	// 检查上下文是否为空，避免空指针操作
	if (m_ctx == nullptr) 
	{
		qDebug() << "Modbus connection is already closed or not initialized";
		return true; // 已断开也算“成功”，避免误判
	}
	modbus_close(m_ctx);
	modbus_free(m_ctx);
	m_ctx = nullptr;
	return true;
}
//16 位整数的高低字节交换 例：0x1234 → 0x3412 
uint16_t ModbusTcpDriver::Uint16_Conver(uint16_t value)
{
	if (m_conver)
	{
		return ((value & 0x00ff) << 8) | ((value & 0xff00) >> 8);
	}
	else
		return value;
}
//float ABCD转换为double
double ModbusTcpDriver::Uint16Vec_to_double(uint16_t value0, uint16_t value1)
{
	// 拆分字节
	uint8_t A = (value0 >> 8) & 0xFF;  // value0高8位
	uint8_t B = value0 & 0xFF;         // value0低8位
	uint8_t C = (value1 >> 8) & 0xFF;  // value1高8位
	uint8_t D = value1 & 0xFF;         // value1低8位

	// 按ABCD顺序组合为32位整数
	uint32_t combined = (static_cast<uint32_t>(A) << 24) | (static_cast<uint32_t>(B) << 16) |  (static_cast<uint32_t>(C) << 8) |  D; 
	// 按CDAB顺序组合为32位整数
	//uint32_t combined = (static_cast<uint32_t>(C) << 24) | (static_cast<uint32_t>(D) << 16) | (static_cast<uint32_t>(A) << 8) | B;
	// 按BADC顺序组合为32位整数
	//uint32_t combined = (static_cast<uint32_t>(B) << 24) | (static_cast<uint32_t>(A) << 16) | (static_cast<uint32_t>(D) << 8) | C;
	// 按DCBA顺序组合
	//uint32_t combined = (static_cast<uint32_t>(D) << 24) | (static_cast<uint32_t>(C) << 16) | (static_cast<uint32_t>(B) << 8) | A;

	//安全转换为float，再转为double返回
	float fTemp;
	//将combined（uint32_t类型）的二进制数据原样拷贝到fTemp（float类型）中，实现两种不同类型间的二进制位复用（类型双关）<（类型双关）必须确保两种类型的大小一致（如uint32_t和float通常都是 4 字节），否则会导致内存越界>
	std::memcpy(&fTemp, &combined, sizeof(fTemp));
	return static_cast<double>(fTemp);
}

void ModbusTcpDriver::SetWriteBuffer(uint16_t address, uint16_t value)
{
	std::lock_guard<std::mutex> lock(_writeMtx);
	m_regWriteBuffer[address] = value;
}
uint16_t ModbusTcpDriver::GetWriteBuffer(uint16_t address)
{
	std::lock_guard<std::mutex> lock(_writeMtx);
	// 使用emplace返回值判断是否插入新元素，减少一次查找
	//注：若 address 不存在：inserted 为 true，it 指向新插入的 (address, 0)
	//若 address 已存在：inserted 为 false，it 指向已存在的元素（值不变
	auto [it, inserted] = m_regWriteBuffer.emplace(address, 0);
	return it->second;
	//不使用自动类型推导
	//std::pair a = m_regWriteBuffer.emplace(address, 0);
	//return a.first->second;

	/*if (m_regWriteBuffer.count(address) == 0)
		m_regWriteBuffer[address] = 0;
	return m_regWriteBuffer[address];*/
}
bool ModbusTcpDriver::write_register(int startAddress, uint16_t value, int functionCodes)
{
	SetWriteBuffer(startAddress, Uint16_Conver(value));
	uint16_t values;
	uint16_t values2[1];
	values = GetWriteBuffer(startAddress);
	values2[0] = GetWriteBuffer(startAddress);

	std::lock_guard<std::mutex> lk(_mtx);
	if (functionCodes == MODBUS_FC_WRITE_SINGLE_REGISTER)
	{
		//成功返回1, 失败返回-1并设置errno
		int rtn = modbus_write_register(m_ctx, startAddress, values);
		if (rtn < 1)
		{
			qDebug() << "write_register failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	else
	{
		int rtn = modbus_write_registers(m_ctx, startAddress, 1, values2);
		if (rtn < 1)
		{
			qDebug() << "write_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	
	return true;
}
bool ModbusTcpDriver::write_register(int startAddress, int count, const std::vector<uint16_t>& values)
{
	uint16_t valueData[256];
	for (int i = 0; i < count; ++i)
	{
		valueData[i] = Uint16_Conver(values.at(i));
	}
	std::lock_guard<std::mutex> lk(_mtx);
	//成功返回写入寄存器个数count, 失败返回-1并设置errno
	int rtn = modbus_write_registers(m_ctx, startAddress, count, valueData);
	if (rtn < count)
	{
		qDebug() << "write_registers failed!:" << modbus_strerror(errno);
		return false;
	}
	return true;
}

bool ModbusTcpDriver::read_register(int startAddress, uint16_t& value, int functionCodes)
{
	int rtn = 0;
	std::lock_guard<std::mutex> lk(_mtx);
	if (functionCodes == MODBUS_FC_READ_HOLDING_REGISTERS)
	{
		//成功返回读取 保持寄存器 个数1, 失败返回-1并设置errno
		rtn = modbus_read_registers(m_ctx, startAddress, 1, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	else
	{
		//成功返回读取 输入寄存器 个数1, 失败返回-1并设置errno
		rtn = modbus_read_input_registers(m_ctx, startAddress, 1, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_input_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	value = Uint16_Conver(m_regReadBuffer[0]);
	return true;
}
bool ModbusTcpDriver::read_register(int startAddress, int count, std::vector<uint16_t>& values, int functionCodes)
{
	if (count > Max_Reg_Count)
		return false;
	int rtn = 0;
	std::lock_guard<std::mutex> lk(_mtx);
	if (functionCodes == MODBUS_FC_READ_HOLDING_REGISTERS)
	{
		//成功返回读取 保持寄存器 个数count, 失败返回-1并设置errno
		rtn = modbus_read_registers(m_ctx, startAddress, count, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	else
	{
		//成功返回读取 输入寄存器 个数count, 失败返回-1并设置errno
		rtn = modbus_read_input_registers(m_ctx, startAddress, count, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_input_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	for (int i = 0; i < count; ++i)
		values.push_back(Uint16_Conver(m_regReadBuffer[i]));
	return true;
}

bool ModbusTcpDriver::read_register(int startAddress, uint8_t& valueLow, uint8_t& valueHigh, int functionCodes)
{
	int rtn = 0;
	std::lock_guard<std::mutex> lk(_mtx);
	if (functionCodes == MODBUS_FC_READ_HOLDING_REGISTERS)
	{
		//成功返回读取 保持寄存器 个数1, 失败返回-1并设置errno
		rtn = modbus_read_registers(m_ctx, startAddress, 1, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	else
	{
		//成功返回读取 输入寄存器 个数1, 失败返回-1并设置errno
		rtn = modbus_read_input_registers(m_ctx, startAddress, 1, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_input_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}

	auto value = m_regReadBuffer[0];
	valueLow = value & 0xff;  // 提取低 8 位
	valueHigh = (value >> 8) & 0xff;  //提取高 8 位
}