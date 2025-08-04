#include "ModbusTcpDriver.h"
#include <qDebug>
ModbusTcpDriver::ModbusTcpDriver()
{
	//�� m_regReadBuffer �����ÿһ���ֽڶ�����Ϊ 0 ��ʵ�������ʼ������
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
	//�����ֽڳ�ʱʱ�� �ڶ��������ǣ��� �����������ǣ�΢��
	modbus_set_byte_timeout(m_ctx, 0, 200000);
	//������Ӧ��ʱʱ�� �ڶ��������ǣ��� �����������ǣ�΢��
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
	// ����������Ƿ�Ϊ�գ������ָ�����
	if (m_ctx == nullptr) 
	{
		qDebug() << "Modbus connection is already closed or not initialized";
		return true; // �ѶϿ�Ҳ�㡰�ɹ�������������
	}
	modbus_close(m_ctx);
	modbus_free(m_ctx);
	m_ctx = nullptr;
	return true;
}
//16 λ�����ĸߵ��ֽڽ��� ����0x1234 �� 0x3412 
uint16_t ModbusTcpDriver::Uint16_Conver(uint16_t value)
{
	if (m_conver)
	{
		return ((value & 0x00ff) << 8) | ((value & 0xff00) >> 8);
	}
	else
		return value;
}

void ModbusTcpDriver::SetWriteBuffer(uint16_t address, uint16_t value)
{
	std::lock_guard<std::mutex> lock(_writeMtx);
	m_regWriteBuffer[address] = value;
}
uint16_t ModbusTcpDriver::GetWriteBuffer(uint16_t address)
{
	std::lock_guard<std::mutex> lock(_writeMtx);
	// ʹ��emplace����ֵ�ж��Ƿ������Ԫ�أ�����һ�β���
	//ע���� address �����ڣ�inserted Ϊ true��it ָ���²���� (address, 0)
	//�� address �Ѵ��ڣ�inserted Ϊ false��it ָ���Ѵ��ڵ�Ԫ�أ�ֵ����
	auto [it, inserted] = m_regWriteBuffer.emplace(address, 0);
	return it->second;
	//��ʹ���Զ������Ƶ�
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
		//�ɹ�����1, ʧ�ܷ���-1������errno
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
	//�ɹ�����д��Ĵ�������count, ʧ�ܷ���-1������errno
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
		//�ɹ����ض�ȡ ���ּĴ��� ����1, ʧ�ܷ���-1������errno
		rtn = modbus_read_registers(m_ctx, startAddress, 1, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	else
	{
		//�ɹ����ض�ȡ ����Ĵ��� ����1, ʧ�ܷ���-1������errno
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
		//�ɹ����ض�ȡ ���ּĴ��� ����count, ʧ�ܷ���-1������errno
		rtn = modbus_read_registers(m_ctx, startAddress, count, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	else
	{
		//�ɹ����ض�ȡ ����Ĵ��� ����count, ʧ�ܷ���-1������errno
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
		//�ɹ����ض�ȡ ���ּĴ��� ����1, ʧ�ܷ���-1������errno
		rtn = modbus_read_registers(m_ctx, startAddress, 1, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}
	else
	{
		//�ɹ����ض�ȡ ����Ĵ��� ����1, ʧ�ܷ���-1������errno
		rtn = modbus_read_input_registers(m_ctx, startAddress, 1, m_regReadBuffer);
		if (rtn < 1)
		{
			qDebug() << "read_input_registers failed!:" << modbus_strerror(errno);
			return false;
		}
	}

	auto value = m_regReadBuffer[0];
	valueLow = value & 0xff;  // ��ȡ�� 8 λ
	valueHigh = (value >> 8) & 0xff;  //��ȡ�� 8 λ
}