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
	double _clockRadius; //ʱ�Ӱ뾶(12����Χ�ɵ�Բ�İ뾶��
	double _arrayX;  //���г� ���
	double _arrayY;  //���п� ���
	double _zStep;   //��zֵ
};