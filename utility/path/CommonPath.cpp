#include "CommonPath.h"
#include <QCoreApplication>


QString CommonPath::GetProgramDir()
{
    // ʹ�� Qt �� QCoreApplication::applicationDirPath()
    // ���س����ִ���ļ����ڵ�Ŀ¼·��
    return QCoreApplication::applicationDirPath() /*+ QDir::separator()*/;
}