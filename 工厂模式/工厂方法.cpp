//�����������ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"

#if 0

enum TYPES
{
	TYPEA, TYPEB
};

class BASE	//�����Ʒ��
{
public:
	virtual void show() = 0;
};

class A :public BASE	//�����Ʒ��
{
public:
	void show()
	{
		cout << "A show!" << endl;
	}
};

class B :public BASE	//�����Ʒ��
{
public:
	void show()
	{
		cout << "B show!" << endl;
	}
};

class Factory	//���󹤳���
{
	virtual BASE* CREATEBASE(enum TYPES c) = 0;
};

class FactoryA:public Factory	//���幤����
{
public:
	BASE* CREATEBASE(enum TYPES c)
	{
		cout << "Create A��" << endl;
		return new A;
	}
};

class FactoryB:public Factory
{
public:
	BASE* CREATEBASE(enum TYPES c)
	{
		cout << "Create B��" << endl;
		return new B;
	}
};

int main()
{
	FactoryA m;
	BASE *p = m.CREATEBASE(TYPEA);
	p->show();
	FactoryB n;
	p = n.CREATEBASE(TYPEB);
	p->show();
	return 0;
}
#endif
