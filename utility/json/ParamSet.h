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
	void Save(QJsonObject& object);
	void Load();
	void Load(QJsonObject& object);

protected:
	void SaveJson(QJsonObject& object);
	void GetJson(QJsonObject& object);

	void AddItem(std::string name, std::string value);

	void SetInt(std::string name, int value);
	void SetDouble(std::string name, double value);
	void SetBool(std::string name, bool value);
	void SetString(std::string name, std::string value);


	int GetInt(std::string name);
	double GetDouble(std::string name);
	bool GetBool(std::string name);
	std::string GetString(std::string name);

protected:
	std::string fileName;
	std::string sectionName;
	std::string paramDir;
	std::map <std::string, std::string> paramMap;
private:



};