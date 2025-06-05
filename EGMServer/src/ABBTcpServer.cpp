
#include "ABBTcpServer.h"
#include <QcoreApplication>
#include <QThread>
#include <QMutexLocker>

ABBTcpServer::ABBTcpServer()
{
	RobotServer = new QTcpServer();
	RobotServer->setMaxPendingConnections(10);  //set max numconnetions

}

ABBTcpServer::~ABBTcpServer()
{
	if (RobotServer!=nullptr)
	{
		RobotServer->deleteLater();
	}
	if (RobotSocket != nullptr)
	{
		RobotSocket->deleteLater();
	}

}


bool ABBTcpServer::StartListening(int port)
{
	Clear();
	if (RobotServer == nullptr)
	{
		return false;
	}
	if (RobotServer->isListening())
	{
		return true;
	}
	bool rtn = RobotServer->listen(QHostAddress::Any, port);
	if (!rtn)
	{
		qDebug() << "Failed to listen:"; //可以使用下log库，生成log文件，暂时不写 todo
		return false;
	}
	// 当有客户端连接时，QTcpServer会发出newConnection信号。 当有新连接时，槽函数就会被调用
	connect(RobotServer, SIGNAL(newConnection()), this, SLOT(onhandleNewConnection()));
	connect(RobotServer, &QTcpServer::acceptError, this, [&](QAbstractSocket::SocketError socketError) {qDebug() << "Socket Error" << (int)socketError; });

	return true;
}
void ABBTcpServer::onhandleNewConnection()
{
	// 调用nextPendingConnection()来获取客户端的QTcpSocket对象，这个对象用于和客户端通信。
	// 取出建立好链接的套接字
	RobotSocket = RobotServer->nextPendingConnection();
	if (RobotSocket == nullptr)
	{
		return;
	}
	// 当有消息发送过来，对方的通信套接字会触发readyRead信号.   在槽函数里读取数据
	connect(RobotSocket, &QTcpSocket::readyRead,this, &ABBTcpServer::onhandleReadyRead);
	// 处理客户端断开连接（清理资源）
	connect(RobotSocket, &QTcpSocket::disconnected, this, &ABBTcpServer::onhandleDisConnected);
}

void ABBTcpServer::onhandleReadyRead()
{
	// bytesAvailable() 函数来检查是否有数据到达，然后再决定是否进行读取操作
	if (!RobotSocket || !RobotSocket->bytesAvailable())
		return;
	// 从通信套接字中读取内容
	QByteArray temp = RobotSocket->readAll();
	QMutexLocker lock(&_mutex);
	_bufferQueue.enqueue(temp);
	qDebug() << "_bufferQueue" << _bufferQueue;
	//ui->RobotReceiveText->append(temp);


}

void ABBTcpServer::onhandleDisConnected()
{
	if (!RobotSocket) 
		return;
	//QList的removeOne方法。删除第一个匹配的元素
	//RobotServer.removeOne(RobotSocket);
	RobotSocket->deleteLater();
	qDebug() << "Client disconnected!"; //可以使用下log库，生成log文件，暂时不写 
}

void ABBTcpServer::StopListening()
{
	if (RobotSocket != nullptr)
	{
		RobotSocket->disconnectFromHost();
		RobotSocket->close();
	}
	

}

void ABBTcpServer::Clear()
{
	_allOutputStr.clear();
	_halfData.clear();
	_bufferQueue.clear();
}

void ABBTcpServer::ParsePacket()
{

}

QString& ABBTcpServer::GetReceivedRobotData()
{
	return _allOutputStr;
}