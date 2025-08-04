#include "PositionDatumsParam.h"

PositionDatumsParam::PositionDatumsParam(std::string fileName, std::string sectionName) :ParamSet(fileName, sectionName)
{
	Init();
	Load();
	GetParam();
}
void PositionDatumsParam::Init()
{
	AddItem("location", "4");
}

void PositionDatumsParam::SetParam()
{
	SetInt("location", _location);
}
void PositionDatumsParam::GetParam()
{
	_location = GetInt("location");
}