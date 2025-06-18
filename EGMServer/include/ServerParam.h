#pragma once
#include <string>
#include "ParamSet.h"
enum RobotType2
{
	Abb,
	Kuka
};
class ServerParam : public ParamSet
{
public:
	ServerParam(std::string fileName, std::string sectionName);

	void Init();
	virtual void SetParam();
	virtual void GetParam();


public:
	std::string _ip;
	int _port;
	RobotType2 _robotType;
};