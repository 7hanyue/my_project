//#pragma once
#ifndef LASERSTUDIO_ABBTCPSERVER_H
#define LASERSTUDIO_ABBTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDomDocument> //QDomDocument 类表示整个 XML 文档

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

	//解包
	void ParsePacket() override;
	QString& GetReceivedRobotData() override;
private slots:
	void onhandleNewConnection(); //处理新客户端连接
	void onhandleReadyRead(); //读取客户端发送的数据
	void onhandleDisConnected(); //处理客户端断开连接的情况
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

	const int SEPARATOR_SIZE = 10; //separator 分隔符
	const char* SEPARATOR_NAME = "</RobData>";

	std::atomic<bool> _isStop{ false };

};

#endif //LASERSTUDIO_ABBTCPSERVER_H
