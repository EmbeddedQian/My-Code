// ��������ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#if 0
class Singleton
{
private:
	static Singleton *singleton;
	Singleton()
	{
		cout << "Singleton()" << endl;
	}
public:
	static Singleton* Get_Instance()
	{
		return singleton;
	}
	class Destroy
	{
	public:
		~Destroy()
		{
			if (Singleton::singleton)
			{
				delete Singleton::singleton;
				cout << "~CSingleton()" << endl;
			}
		}
	};
	static Destroy destroy;
};
Singleton* Singleton::singleton = new Singleton();
Singleton::Destroy destroy;
int main()
{
	cout << "process start!" << endl;
	Singleton* s1 = Singleton::Get_Instance();
	Singleton* s2 = Singleton::Get_Instance();
	cout << s1 << endl;
	cout << s2 << endl;
}
#endif
