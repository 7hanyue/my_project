#include "Subject.h"
#include "Observer.h"


Subject::Subject()
{
	_observerList.clear();
	_observerStrList.clear();
}

void Subject::Attach(QWeakPointer<Observer> ob, QString str)
{
	QMutexLocker locker(&_mtxObserver);
	//auto sp = ob.lock();
	QList<QWeakPointer<Observer>>::iterator it = _observerList.begin();
	while (it != _observerList.end())
	{
		if (*(it) == ob) //检查是否已存在该观察者
			return;   //存在则不重复添加，保证列表唯一
		++it;
	}
	_observerList.push_back(ob);
	_observerStrList.push_back(str);

}

void Subject::Detach(QWeakPointer<Observer> ob, QString str)
{
	QMutexLocker locker(&_mtxObserver);
	//找到匹配的观察者弱指针则从列表中删除
	for (auto it = _observerList.begin(); it != _observerList.end(); ++it)
	{
		if (*it == ob)
		{ 
			_observerList.erase(it);
			break;  //break 会跳过这一步(即 执行 ++it)
		}
	}
	//找到匹配的字符串则从列表中删除
	for (auto it = _observerStrList.begin(); it != _observerStrList.end(); ++it)
	{
		if (*it == str)
		{
			_observerStrList.erase(it);
			break;  //break 会跳过这一步(即 执行 ++it)
		}
	}
}

//安全通知观察者并清理已销毁观察者的多线程代码 
void Subject::Notify(int status)
{
	QMutexLocker locker(&_mtxObserver);
	auto it = _observerList.begin();
	while (it != _observerList.end())
	{
		auto sp = (*it).lock(); //尝试将 QWeakPointer 提升为 QSharedPointer
		
		if (!sp.isNull())//提升成功（观察者对象未销毁 ）
		{
			sp->Update(status);  //调用 Update(status) 通知（)观察者
			++it;  //接着遍历观察者列表
		}
		else  //提升失败（观察者对象已销毁 ）
		{
			it = _observerList.erase(it);  //从 _observerList 中移除该弱指针，避免无效引用

			if (it == _observerList.end())  //移除后若迭代器到达列表末尾，跳出while循环
				break;
		}
	}
}

void Subject::Notify(QString status)
{
	QMutexLocker locker(&_mtxObserver);
	auto it = _observerList.begin();
	while (it != _observerList.end())
	{
		auto sp = (*it).lock(); //尝试将 QWeakPointer 提升为 QSharedPointer

		if (!sp.isNull())//提升成功（观察者对象未销毁 ）
		{
			sp->Update(status.toLocal8Bit().toStdString());  //调用 Update(status) 通知（)观察者
			++it;  //接着遍历观察者列表
		}
		else  //提升失败（观察者对象已销毁 ）
		{
			it = _observerList.erase(it);  //从 _observerList 中移除该弱指针，避免无效引用

			if (it == _observerList.end())  //移除后若迭代器到达列表末尾，跳出while循环
				break;
		}
	}
}


void Subject::DetachAll()
{
	_observerList.clear();
	_observerStrList.clear();
}
