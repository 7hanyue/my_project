
#ifndef GLOBALVER_H
#define GLOBALVER_H

#define NET_PACKET_LTNGTH_BYTES 295  //包数据占几个字节 目前数据长度可能295、293、294不固定

class GlobalVar
{
public:
	GlobalVar();
	static bool ServerBtnStatus;
	static int RobotPort;
	static int RobSocketDescriport;

	//~GlobalVar();
//private:

};

#endif // GLOBALVER_H

//GlobalVar::GlobalVar()
//{
//}
//
//GlobalVar::~GlobalVar()
//{
//}

