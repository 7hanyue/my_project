#pragma once
#include <string>
#include "ParamSet.h"
enum ReferenceLocation //九宫格参考位
{
    top_left = 0,
    top, 
    top_right, 
    left, 
    center, 
    right, 
    bottom_left, 
    bottom, 
    bottom_right
};
class PositionDatumsParam : public ParamSet
{
public:
	PositionDatumsParam(std::string fileName, std::string sectionName);
	virtual void Init();
	void SetParam() override;
	void GetParam() override;

public:
	int _location = static_cast<int>(ReferenceLocation::center);//默认在中心点位
};