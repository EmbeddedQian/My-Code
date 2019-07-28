//�������ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#if 0
class CPHONE	//�����ֻ���
{
public:
	virtual void show() = 0;
};

class Cxiaomiphone :public CPHONE	//�����ƷС���ֻ���
{
public:
	void show()
	{
		cout << "xiaomi phone produce!" << endl;
	}
};

class Chuaweiphone :public CPHONE	//�����Ʒ��Ϊ�ֻ���
{
public:
	void show()
	{
		cout << "huawei phone produce!" << endl;
	}
};

class CTV	//���������
{
public:
	virtual void show() = 0;
};

class Cxiaomitv :public CTV	//�����ƷС�׵�����
{
public:
	void show()
	{
		cout << "xiaomi TV produce!" << endl;
	}
};

class Chuaweitv :public CTV	//�����Ʒ��Ϊ������
{
public:
	void show()
	{
		cout << "huawei TV produce!" << endl;
	}
};

class Factory	//���󹤳���
{
public:
	virtual CPHONE* CREATEPHONE() = 0;
	virtual CTV* CREATETV() = 0;
};

class Factory_XIAOMI :public Factory	//����С�׹�����
{
public:
	CPHONE* CREATEPHONE()
	{
		return new Cxiaomiphone();
	}
	CTV* CREATETV()
	{
		return  new Cxiaomitv();
	}
};

class Factory_HUAWEI :public Factory	//���廪Ϊ������
{
public:
	CPHONE* CREATEPHONE()
	{
		return new Chuaweiphone();
	}
	CTV* CREATETV()
	{
		return  new Chuaweitv();
	}
};

int main()
{
	//С��
	Factory* factory = new Factory_XIAOMI();
	CPHONE* phone = factory->CREATEPHONE();
	CTV* tv = factory->CREATETV();
	phone->show();
	tv->show();

	//��Ϊ
	factory = new Factory_HUAWEI();
	phone = factory->CREATEPHONE();
	tv = factory->CREATETV();
	phone->show();
	tv->show();

	delete factory;
	delete phone;
	delete tv;
	return 0;
}

#endif
