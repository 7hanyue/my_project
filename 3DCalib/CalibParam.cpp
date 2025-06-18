#include "CalibParam.h"

CalibParam::CalibParam(std::string fileName, std::string sectionName) :ParamSet(fileName, sectionName)
{
	Init();
	Load();
	GetParam();
}
void CalibParam::Init()
{
	AddItem("_clockRadius", "10");
	AddItem("_arrayX", "50");
	AddItem("_arrayY", "50");
	AddItem("_zStep", "0.5");
}

void CalibParam::SetParam()
{
	SetDouble("_clockRadius", _clockRadius);
	SetDouble("_arrayX", _arrayX);
	SetDouble("_arrayY", _arrayY);
	SetDouble("_zStep", _zStep);
}
void CalibParam::GetParam()
{
	_clockRadius = GetDouble("_clockRadius");
	_arrayX = GetDouble("_arrayX");
	_arrayY = GetDouble("_arrayY");
	_zStep = GetDouble("_zStep");

}