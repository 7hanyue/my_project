#pragma once
#include <string>
#define qtthis
//#define cxxthis

#ifdef qtthis
#include <QEnableSharedFromThis>
#else
#include <memory>
#endif // qtthis

class _declspec(dllexport) Observer
{
public:
	Observer() = default;
	virtual ~Observer() = default;
	virtual void Update(int status) {};
	virtual void Update(std::string status) {};
};
