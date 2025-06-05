#include "EGMServer.h"
#include <QApplication>

#include <iostream>


//#include <sstream>
//##include "ILogPlugin.h"
//use namespace LS_CORE_NAMESPACE_SCOPE;
//use namespace LS_LOG_NAMESPACE_SCOPE;

using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EGMServer w;
	w.show();
	return a.exec();

}

