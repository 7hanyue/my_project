#include "CommonPath.h"
#include <QCoreApplication>


QString CommonPath::GetProgramDir()
{
    // 使用 Qt 的 QCoreApplication::applicationDirPath()
    // 返回程序可执行文件所在的目录路径
    return QCoreApplication::applicationDirPath() /*+ QDir::separator()*/;
}