
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
		qDebug() << "Failed to listen:"; //����ʹ����log�⣬����log�ļ�����ʱ��д todo
		return false;
	}
	// ���пͻ�������ʱ��QTcpServer�ᷢ��newConnection�źš� ����������ʱ���ۺ����ͻᱻ����
	connect(RobotServer, SIGNAL(newConnection()), this, SLOT(onhandleNewConnection()));
	connect(RobotServer, &QTcpServer::acceptError, this, [&](QAbstractSocket::SocketError socketError) {qDebug() << "Socket Error" << (int)socketError; });

	return true;
}
void ABBTcpServer::onhandleNewConnection()
{
	// ����nextPendingConnection()����ȡ�ͻ��˵�QTcpSocket��������������ںͿͻ���ͨ�š�
	// ȡ�����������ӵ��׽���
	RobotSocket = RobotServer->nextPendingConnection();
	if (RobotSocket == nullptr)
	{
		return;
	}
	// ������Ϣ���͹������Է���ͨ���׽��ֻᴥ��readyRead�ź�.   �ڲۺ������ȡ����
	connect(RobotSocket, &QTcpSocket::readyRead,this, &ABBTcpServer::onhandleReadyRead);
	// ����ͻ��˶Ͽ����ӣ�������Դ��
	connect(RobotSocket, &QTcpSocket::disconnected, this, &ABBTcpServer::onhandleDisConnected);
}

void ABBTcpServer::onhandleReadyRead()
{
	// bytesAvailable() ����������Ƿ������ݵ��Ȼ���پ����Ƿ���ж�ȡ����
	if (!RobotSocket || !RobotSocket->bytesAvailable())
		return;
	// ��ͨ���׽����ж�ȡ����
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
	//QList��removeOne������ɾ����һ��ƥ���Ԫ��
	//RobotServer.removeOne(RobotSocket);
	RobotSocket->deleteLater();
	qDebug() << "Client disconnected!"; //����ʹ����log�⣬����log�ļ�����ʱ��д 
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