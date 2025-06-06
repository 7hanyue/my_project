#include "ParamSet.h"
#include "CommonPath.h"
//#include <iostream>
#include <QDebug>
#include <QJsonDocument>
#include <QFile>
#include <QDir>
//#include "windows.h"

const std::string fileFormat = ".json";
ParamSet::ParamSet(std::string fileName, std::string sectionName, std::string paramDir) : fileName(fileName), sectionName(sectionName), paramDir(paramDir)
{

}
void ParamSet::Save()
{
	QJsonObject object;
	Save(object);
	SaveJson(object);

}
void ParamSet::Save(QJsonObject& object)
{
	SetParam();
	for (std::map<std::string, std::string>::iterator it = paramMap.begin(); it != paramMap.end(); ++it)
	{
		object.insert(QString::fromStdString(it->first),QString::fromLocal8Bit(it->second.c_str()));

	}
}
void ParamSet::Load() 
{
	QJsonObject object;
	GetJson(object);
	Load(object);
	
}
void ParamSet::Load(QJsonObject& object)
{
	for (std::map<std::string, std::string>::iterator it = paramMap.begin(); it != paramMap.end(); ++it)
	{ 
		//ֱ��ʹ��[]������ ,��ȡobject�Ķ���  
		//obj["key"],��ȡ����Ӧ��ֵ,������������ʱ�����һ����ֵ
		std::string strValue = (std::string) object[QString::fromStdString(it->first)].toString().toLocal8Bit();  
		if (strValue != "")
			paramMap[it->first] = strValue;
	}

}

void ParamSet::SaveJson(QJsonObject& object)
{
	//1�� JSON ����ת��Ϊ�ĵ�
	QJsonDocument jsonDoc(object);
	//2ѡ�� JSON ��ʽ��Indented ������(Ĭ�ϣ���Compact ���ո�ʽ��
	QByteArray jsonData = jsonDoc.toJson();

	std::string filePath = paramDir + fileName + fileFormat;
	QString filePath1 = CommonPath::GetProgramDir() + QString::fromStdString(filePath);
	try
	{ 
		//3������ Ŀ¼
		QDir dir(CommonPath::GetProgramDir() + QString::fromStdString(paramDir));
		if (!dir.exists()) 
		{
			//���� dir ���������·������ CommonPath::GetProgramDir() + paramDir ƴ�ӣ�
			if (!dir.mkdir("")) 
			{
				qWarning() << "����·��ʧ��:";
			}
		}

		// 4��д���ļ�
		QFile file(filePath1);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			qWarning() << "�޷����ļ�:" << file.errorString();
		}
		file.write(jsonData); //дJSON ����

		file.close();
	}
	catch (...)
	{
		qDebug() << "Save ParamSet failed in ParamSet.cpp"; //����spdlog�󻻵�
	}
}
void ParamSet::GetJson(QJsonObject& object)
{
	std::string filePath = paramDir + fileName + fileFormat;
	QString filePath1 = CommonPath::GetProgramDir() + QString::fromStdString(filePath);

	try
	{
		// 1. �� JSON �ļ�
		QFile file(filePath1);
		if (!file.exists())
			return;
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			qWarning() << "�޷����ļ�:" << file.errorString();
		}

		// 2. ��ȡ�ļ�����
		QByteArray jsonData = file.readAll();
		file.close();

		//1�� jsonData��QByteArray ���ͣ��洢 JSON ��ʽ���ֽ����ݣ�����Ϊ QJsonDocument��JSON �ĵ�����
		QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
		//2�� QJsonDocument ����ȡ �� JSON ����QJsonObject ���ͣ������� object ���������������� JSON ����ʹ�á�
		object = jsonDoc.object();
	}
	catch (...)
	{
		qDebug() << "Get ParamSet failed in ParamSet.cpp"; //����spdlog�󻻵�
	}
	
	
}

void ParamSet::AddItem(std::string name, std::string value)
{
	try
	{
		paramMap[name] = value;
	}
	catch (...)
	{
		qDebug() << "AddItem failed in ParamSet.cpp"; //����spdlog�󻻵�
	}
}

void ParamSet::SetInt(std::string name, int value)
{
	try
	{
		//���͡�double��boolת��Ϊstring
		//����std::to_string��C++11 �������汾)
		std::string str = std::to_string(value);
		paramMap[name] = value;
	}
	catch (...)
	{
		qDebug() << "SetInt failed in ParamSet.cpp"; //����spdlog�󻻵�
	}
}
void ParamSet::SetDouble(std::string name, double value)
{
	try
	{
		//���͡�double��boolת��Ϊstring
		//����std::to_string��C++11 �������汾)
		std::string str = std::to_string(value);
		paramMap[name] = value;
	}
	catch (...)
	{
		qDebug() << "SetDouble failed in ParamSet.cpp"; //����spdlog�󻻵�
	}
}
void ParamSet::SetBool(std::string name, bool value)
{
	try
	{
		//���͡�double��boolת��Ϊstring
		//����std::to_string��C++11 �������汾)
		std::string str = std::to_string(value);
		paramMap[name] = value;
	}
	catch (...)
	{
		qDebug() << "SetBool failed in ParamSet.cpp"; //����spdlog�󻻵�
	}
}
void ParamSet::SetString(std::string name, std::string value)
{
	try
	{
		paramMap[name] = value;
	}
	catch (...)
	{
		qDebug() << "SetString failed in ParamSet.cpp"; //����spdlog�󻻵�
	}
}

int ParamSet::GetInt(std::string name)
{
	try
	{
		//��stringת��Ϊ����std::stoi(str); 
		std::string str = paramMap[name];
		int value = std::stoi(str);
		return value;
	}
	catch (...)
	{
		qDebug() << "GetInt failed in ParamSet.cpp"; //����spdlog�󻻵�
		return 0;
	}
}
double ParamSet::GetDouble(std::string name)
{
	try
	{
		//��stringת��Ϊdouble std::stod(str); 
		std::string str = paramMap[name];
		double value = std::stod(str);
		return value;
	}
	catch (...)
	{
		qDebug() << "GetDouble failed in ParamSet.cpp"; //����spdlog�󻻵�
		return 0.0;
	}
}
bool ParamSet::GetBool(std::string name)
{
	try
	{
		std::string str = paramMap[name];
		if(str == "true" || str == "1")
			return true;
		if (str == "false" || str == "0")
			return false;
	}
	catch (...)
	{
		qDebug() << "GetBool failed in ParamSet.cpp"; //����spdlog�󻻵�
		return false;
	}
}
std::string ParamSet::GetString(std::string name)
{
	try
	{
		std::string value = paramMap[name];
		return value;
		
	}
	catch (...)
	{
		qDebug() << "GetString failed in ParamSet.cpp"; //����spdlog�󻻵�
		return "";
	}
}

