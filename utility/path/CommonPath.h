#pragma once

#include <QString>

//#include <QDir>
class CommonPath
{
public:
    //为什么在这里声明为静态的，核心原因是 让函数直接属于类（而非对象实例）
    /*1、无需创建对象即可调用.  静态函数通过 类名::函数名 直接调用（如 CommonPath::GetProgramDir()）
    * 2、功能与类绑定，而非对象。获取程序目录的功能，属于整个程序的 “全局特性”，而非某个 CommonPath 对象的私有行为
    * 3、封装与效率：避免对象冗余。 静态函数不需要为每个对象复制一份代码（内存中只有一份副本），也无需维护对象的构造 / 析构开销。对于工具函数来说，这样的设计更高效、更简洁。
     */
    static QString GetProgramDir();
};