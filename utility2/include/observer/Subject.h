#pragma once
#include <QWeakPointer>
#include <QMutex>
#include <QList>

class Observer;

class _declspec(dllexport) Subject
{
public:
	Subject();
	virtual ~Subject() = default;

	virtual void Attach(QWeakPointer<Observer>, QString str = "");
	virtual void Detach(QWeakPointer<Observer>, QString str = "");
	virtual void Notify(int status);
	virtual void Notify(QString status);
	virtual void DetachAll();
private:

	QList<QWeakPointer<Observer>> _observerList;
	QList<QString> _observerStrList;
	QMutex _mtxObserver;
};
