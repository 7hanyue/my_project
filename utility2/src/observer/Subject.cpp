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
		if (*(it) == ob) //����Ƿ��Ѵ��ڸù۲���
			return;   //�������ظ���ӣ���֤�б�Ψһ
		++it;
	}
	_observerList.push_back(ob);
	_observerStrList.push_back(str);

}

void Subject::Detach(QWeakPointer<Observer> ob, QString str)
{
	QMutexLocker locker(&_mtxObserver);
	//�ҵ�ƥ��Ĺ۲�����ָ������б���ɾ��
	for (auto it = _observerList.begin(); it != _observerList.end(); ++it)
	{
		if (*it == ob)
		{ 
			_observerList.erase(it);
			break;  //break ��������һ��(�� ִ�� ++it)
		}
	}
	//�ҵ�ƥ����ַ�������б���ɾ��
	for (auto it = _observerStrList.begin(); it != _observerStrList.end(); ++it)
	{
		if (*it == str)
		{
			_observerStrList.erase(it);
			break;  //break ��������һ��(�� ִ�� ++it)
		}
	}
}

//��ȫ֪ͨ�۲��߲����������ٹ۲��ߵĶ��̴߳��� 
void Subject::Notify(int status)
{
	QMutexLocker locker(&_mtxObserver);
	auto it = _observerList.begin();
	while (it != _observerList.end())
	{
		auto sp = (*it).lock(); //���Խ� QWeakPointer ����Ϊ QSharedPointer
		
		if (!sp.isNull())//�����ɹ����۲��߶���δ���� ��
		{
			sp->Update(status);  //���� Update(status) ֪ͨ��)�۲���
			++it;  //���ű����۲����б�
		}
		else  //����ʧ�ܣ��۲��߶��������� ��
		{
			it = _observerList.erase(it);  //�� _observerList ���Ƴ�����ָ�룬������Ч����

			if (it == _observerList.end())  //�Ƴ����������������б�ĩβ������whileѭ��
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
		auto sp = (*it).lock(); //���Խ� QWeakPointer ����Ϊ QSharedPointer

		if (!sp.isNull())//�����ɹ����۲��߶���δ���� ��
		{
			sp->Update(status.toLocal8Bit().toStdString());  //���� Update(status) ֪ͨ��)�۲���
			++it;  //���ű����۲����б�
		}
		else  //����ʧ�ܣ��۲��߶��������� ��
		{
			it = _observerList.erase(it);  //�� _observerList ���Ƴ�����ָ�룬������Ч����

			if (it == _observerList.end())  //�Ƴ����������������б�ĩβ������whileѭ��
				break;
		}
	}
}


void Subject::DetachAll()
{
	_observerList.clear();
	_observerStrList.clear();
}
