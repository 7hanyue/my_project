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
	// -----------------�������ͻ���Client)**************
	// ---
	//����modbus
	bool Connect(const std::string& ip, int port, int slave);
	//�Ͽ�����
	bool DisConnect();

	//��С��ת��
	uint16_t Uint16_Conver(uint16_t value);
	//�Ƿ���д�С��ת����־λ
	void SetConver(bool b)
	{
		m_conver = b;
	}
	//float ABCDת��Ϊdouble
	double Uint16Vec_to_double(uint16_t value0, uint16_t value1);
	
	//���Ĵ�����д����
	bool write_register(int startAddress, uint16_t value, int functionCodes = MODBUS_FC_MASK_WRITE_REGISTER);
	//const��ʾ ��������������������ã���ζ�ź����ڲ������޸������е�Ԫ��
	//&����ʾ �����á�,���������ԭ������һ�� �������������Ǹ�����������������˸���
	bool write_register(int startAddress, int count, const std::vector<uint16_t>& values);

	//�ӼĴ����ж�����
	bool read_register(int startAddress, uint16_t& value, int functionCodes = MODBUS_FC_READ_HOLDING_REGISTERS);

	bool read_register(int startAddress, int count, std::vector<uint16_t>& values, int functionCodes = MODBUS_FC_READ_HOLDING_REGISTERS);

	bool read_register(int startAddress, uint8_t& valueLow,uint8_t& valueHigh ,int functionCodes = MODBUS_FC_READ_HOLDING_REGISTERS);

private:
	void SetWriteBuffer(uint16_t address, uint16_t value);
	uint16_t GetWriteBuffer(uint16_t address);
	
private:
	modbus_t* m_ctx = nullptr;
	bool m_conver = false;

	std::mutex _mtx;  //��д�Ĵ�����

	std::mutex _writeMtx;  //д������
	std::map<uint16_t, uint16_t> m_regWriteBuffer{};

	uint16_t m_regReadBuffer[Max_Reg_Count];
};