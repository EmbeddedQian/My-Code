#include"stdafx.h"
//#include <iostream>
//#include <vector>
//using namespace std;
//
//typedef vector<int> Vec;
//typedef vector<int>::iterator VecIt;
//
//void print(Vec &v)
//{
//	VecIt it;
//	for (it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//
//	cout << endl;
//}
//
//void deleteValueFromVector(Vec &v, int n = 5)
//{
//	VecIt it;
//	for (it = v.begin(); it != v.end();/*������������*/)
//	{
//		if (0 == *it % n)
//		{
//			it=v.erase(it);// vectorԪ���Զ���ǰŲ����(������map����Ԫ�ز����Զ�Ų��)�� ���Բ����ٰ�it����++��
//		}
//		else
//		{
//			it++;
//		}
//	}
//}
//
//int main()
//{
//	Vec v;
//	int i = 0;
//	for (i = 0; i < 21; i++)
//	{
//		v.push_back(i); // ������ɵɵ�����±���
//	}
//
//	print(v);
//
//	deleteValueFromVector(v); // ����ok
//	print(v);
//
//	return 0;
//}