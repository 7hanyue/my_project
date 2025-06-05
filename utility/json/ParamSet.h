#pragma once

#include <string>
#include <map>
#include <QJsonObject>
class ParamSet
{
public:
	ParamSet() = default;
	~ParamSet() = default;
	ParamSet(std::string fileName, std::string sectionName, std::string paramDir = "//configuration//");
	//ParamSet(QJsonObject& object);
	virtual void Init() = 0;
	virtual void SetParam() {};
	virtual void GetParam() {};

	void Save();
	//void Save(QJsonObject& object);
	void Load();
	void Load(QJsonObject& object);

protected:
	std::string fileName;
	std::string sectionName;
	std::string paramDir;
	map <string, string> paramMap;
private:



};