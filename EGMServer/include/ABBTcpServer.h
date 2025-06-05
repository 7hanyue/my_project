//#pragma once
#ifndef LASERSTUDIO_ABBTCPSERVER_H
#define LASERSTUDIO_ABBTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDomDocument> //QDomDocument ���ʾ���� XML �ĵ�

#include <QMutex>
#include <QQueue>
#include "globalvar.h"
#include "IRobotServer.h"


class ABBTcpServer: public IRobotServer
{
	Q_OBJECT
public:
	ABBTcpServer();
	~ABBTcpServer();

	bool StartListening(int port) override;
	void StopListening() override;
	void Clear() override;

	//���
	void ParsePacket() override;
	QString& GetReceivedRobotData() override;
private slots:
	void onhandleNewConnection(); //�����¿ͻ�������
	void onhandleReadyRead(); //��ȡ�ͻ��˷��͵�����
	void onhandleDisConnected(); //����ͻ��˶Ͽ����ӵ����
private:
	struct JczJoint
	{
		double j[6] = { 0,0,0,0,0,0 };
	};

	QTcpServer* RobotServer = nullptr;
	QTcpSocket* RobotSocket = nullptr;

	QMutex _mutex;
	QQueue<QByteArray> _bufferQueue{};
	QByteArray _halfData = "";
	QString _allOutputStr = "";

	const int SEPARATOR_SIZE = 10; //separator �ָ���
	const char* SEPARATOR_NAME = "</RobData>";

	std::atomic<bool> _isStop{ false };

};

#endif //LASERSTUDIO_ABBTCPSERVER_H
