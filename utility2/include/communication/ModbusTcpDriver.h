#pragma once
#if defined(WIN32) || defined (WIN64)
#ifdef ModbusTcp_Plugin
#define ModbusTcpDriverExport __declspec(dllexport)
#else
#define ModbusTcpDriverExport __declspec(dllimport)
#endif
#else
#ifndef ModbusTcpDriverExport
#define ModbusTcpDriverExport
#endif
#endif

#include <QObject>
#include <mutex>
#include "modbus.h"

const int Max_Reg_Count = 256;

class ModbusTcpDriverExport ModbusTcpDriver : public QObject
{
	Q_OBJECT
public:
	ModbusTcpDriver();
	~ModbusTcpDriver();

	bool IsOpen()
	{
		return m_ctx == nullptr ? false : true;
	}
	//---
	// -----------------主机（客户端Client)**************
	// ---
	//连接modbus
	bool Connect(const std::string& ip, int port, int slave);
	//断开连接
	bool DisConnect();

	//大小端转换
	uint16_t Uint16_Conver(uint16_t value);
	//是否进行大小端转换标志位
	void SetConver(bool b)
	{
		m_conver = b;
	}
	//float ABCD转换为double
	double Uint16Vec_to_double(uint16_t value0, uint16_t value1);
	
	//往寄存器中写数据
	bool write_register(int startAddress, uint16_t value, int functionCodes = MODBUS_FC_MASK_WRITE_REGISTER);
	//const表示 “常量”，修饰这个引用，意味着函数内部不能修改容器中的元素
	//&：表示 “引用”,这个参数是原容器的一个 “别名”，而非副本。用引用则避免了复制
	bool write_register(int startAddress, int count, const std::vector<uint16_t>& values);

	//从寄存器中读数据
	bool read_register(int startAddress, uint16_t& value, int functionCodes = MODBUS_FC_READ_HOLDING_REGISTERS);

	bool read_register(int startAddress, int count, std::vector<uint16_t>& values, int functionCodes = MODBUS_FC_READ_HOLDING_REGISTERS);

	bool read_register(int startAddress, uint8_t& valueLow,uint8_t& valueHigh ,int functionCodes = MODBUS_FC_READ_HOLDING_REGISTERS);

private:
	void SetWriteBuffer(uint16_t address, uint16_t value);
	uint16_t GetWriteBuffer(uint16_t address);
	
private:
	modbus_t* m_ctx = nullptr;
	bool m_conver = false;

	std::mutex _mtx;  //读写寄存器锁

	std::mutex _writeMtx;  //写缓存锁
	std::map<uint16_t, uint16_t> m_regWriteBuffer{};

	uint16_t m_regReadBuffer[Max_Reg_Count];
};