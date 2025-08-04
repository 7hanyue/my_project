#pragma once
#include <string>
#include "ParamSet.h"
enum ReferenceLocation //�Ź���ο�λ
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
	int _location = static_cast<int>(ReferenceLocation::center);//Ĭ�������ĵ�λ
};