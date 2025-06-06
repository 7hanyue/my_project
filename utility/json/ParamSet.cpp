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
		//直接使用[]操作符 ,获取object的对象。  
		//obj["key"],获取键对应的值,但当键不存在时会插入一个空值
		std::string strValue = (std::string) object[QString::fromStdString(it->first)].toString().toLocal8Bit();  
		if (strValue != "")
			paramMap[it->first] = strValue;
	}

}

void ParamSet::SaveJson(QJsonObject& object)
{
	//1将 JSON 对象转换为文档
	QJsonDocument jsonDoc(object);
	//2选择 JSON 格式（Indented 带缩进(默认），Compact 紧凑格式）
	QByteArray jsonData = jsonDoc.toJson();

	std::string filePath = paramDir + fileName + fileFormat;
	QString filePath1 = CommonPath::GetProgramDir() + QString::fromStdString(filePath);
	try
	{ 
		//3、操作 目录
		QDir dir(CommonPath::GetProgramDir() + QString::fromStdString(paramDir));
		if (!dir.exists()) 
		{
			//创建 dir 代表的完整路径（由 CommonPath::GetProgramDir() + paramDir 拼接）
			if (!dir.mkdir("")) 
			{
				qWarning() << "创建路径失败:";
			}
		}

		// 4、写入文件
		QFile file(filePath1);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			qWarning() << "无法打开文件:" << file.errorString();
		}
		file.write(jsonData); //写JSON 数据

		file.close();
	}
	catch (...)
	{
		qDebug() << "Save ParamSet failed in ParamSet.cpp"; //引入spdlog后换掉
	}
}
void ParamSet::GetJson(QJsonObject& object)
{
	std::string filePath = paramDir + fileName + fileFormat;
	QString filePath1 = CommonPath::GetProgramDir() + QString::fromStdString(filePath);

	try
	{
		// 1. 打开 JSON 文件
		QFile file(filePath1);
		if (!file.exists())
			return;
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			qWarning() << "无法打开文件:" << file.errorString();
		}

		// 2. 读取文件内容
		QByteArray jsonData = file.readAll();
		file.close();

		//1将 jsonData（QByteArray 类型，存储 JSON 格式的字节数据）解析为 QJsonDocument（JSON 文档对象）
		QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
		//2从 QJsonDocument 中提取 根 JSON 对象（QJsonObject 类型），存入 object 变量，供后续解析 JSON 内容使用。
		object = jsonDoc.object();
	}
	catch (...)
	{
		qDebug() << "Get ParamSet failed in ParamSet.cpp"; //引入spdlog后换掉
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
		qDebug() << "AddItem failed in ParamSet.cpp"; //引入spdlog后换掉
	}
}

void ParamSet::SetInt(std::string name, int value)
{
	try
	{
		//整型、double、bool转换为string
		//采用std::to_string（C++11 及后续版本)
		std::string str = std::to_string(value);
		paramMap[name] = value;
	}
	catch (...)
	{
		qDebug() << "SetInt failed in ParamSet.cpp"; //引入spdlog后换掉
	}
}
void ParamSet::SetDouble(std::string name, double value)
{
	try
	{
		//整型、double、bool转换为string
		//采用std::to_string（C++11 及后续版本)
		std::string str = std::to_string(value);
		paramMap[name] = value;
	}
	catch (...)
	{
		qDebug() << "SetDouble failed in ParamSet.cpp"; //引入spdlog后换掉
	}
}
void ParamSet::SetBool(std::string name, bool value)
{
	try
	{
		//整型、double、bool转换为string
		//采用std::to_string（C++11 及后续版本)
		std::string str = std::to_string(value);
		paramMap[name] = value;
	}
	catch (...)
	{
		qDebug() << "SetBool failed in ParamSet.cpp"; //引入spdlog后换掉
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
		qDebug() << "SetString failed in ParamSet.cpp"; //引入spdlog后换掉
	}
}

int ParamSet::GetInt(std::string name)
{
	try
	{
		//将string转换为整型std::stoi(str); 
		std::string str = paramMap[name];
		int value = std::stoi(str);
		return value;
	}
	catch (...)
	{
		qDebug() << "GetInt failed in ParamSet.cpp"; //引入spdlog后换掉
		return 0;
	}
}
double ParamSet::GetDouble(std::string name)
{
	try
	{
		//将string转换为double std::stod(str); 
		std::string str = paramMap[name];
		double value = std::stod(str);
		return value;
	}
	catch (...)
	{
		qDebug() << "GetDouble failed in ParamSet.cpp"; //引入spdlog后换掉
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
		qDebug() << "GetBool failed in ParamSet.cpp"; //引入spdlog后换掉
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
		qDebug() << "GetString failed in ParamSet.cpp"; //引入spdlog后换掉
		return "";
	}
}

