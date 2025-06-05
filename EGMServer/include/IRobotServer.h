/*-------------
File description:
The description of this header file, including purposes and usage

Date            Name                 Description of Change
dd-mm-yyyy     XXX                  Written
--------------*/
#ifndef LASERSTUDIO_IROBOTSERVER_H
#define LASERSTUDIO_IROBOTSERVER_H

#include <QObject>

class IRobotServer: public QObject
{
Q_OBJECT
public:
	IRobotServer()= default;
	virtual ~IRobotServer()= default;
	virtual bool StartListening(int port) = 0;
	virtual void StopListening() = 0;
	virtual void Clear() = 0;
	virtual void ParsePacket() = 0;
	virtual QString& GetReceivedRobotData() = 0;


signals:
	void serverButtonIconStatusUpdate(bool isEnable);
	void sendRealtimeReceivedRobotData(const QString &data);

};


#endif //LASERSTUDIO_ABBTCPSERVER_H
//IRobotServer::IRobotServer()
//{
//}
//
//IRobotServer::~IRobotServer()
//{
//}