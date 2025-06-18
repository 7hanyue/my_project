#include "ServerParam.h"
ServerParam::ServerParam(std::string fileName, std::string sectionName):ParamSet(fileName, sectionName)
{
	Init();
	Load();
	GetParam();
}
void ServerParam::Init()
{
	AddItem("robotType","0");
}
void ServerParam::SetParam()
{
	SetInt("robotType", static_cast<int>(_robotType));
}
void ServerParam::GetParam()
{
	_robotType = (RobotType2)GetInt("robotType");
}