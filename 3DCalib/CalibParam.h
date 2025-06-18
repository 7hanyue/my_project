#pragma once
#include <string>
#include "ParamSet.h"
class CalibParam : public ParamSet
{
public:
	CalibParam(std::string fileName, std::string sectionName);
	virtual void Init();
	void SetParam() override;
	void GetParam() override;

public:
	double _clockRadius; //时钟半径(12个点围成的圆的半径）
	double _arrayX;  //阵列长 间距
	double _arrayY;  //阵列宽 间距
	double _zStep;   //振镜z值
};