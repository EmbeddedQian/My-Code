#include"pch.h"
#if 0
void SISort(vector<int>&vec)
{
	int i, j;		//ѭ������
	int temp;		//��ʱ��
	for (i = 1; i < vec.size(); ++i)	//ÿ��ѭ������һ����vec[i]
	{
		j = i;
		temp = vec[i];	//��ʱ����Ŵ���������� ������ֺ��ƻḲ�ǵ�vec[i]��λ��
		//j�������0 ����һֱ�� ���ֻ�ܼ���1 Ҳ���Ǵ������������Ŀǰ��С���� ���뵽��һλ��С��λ��
		while (j > 0 && temp< vec[j - 1])	
		{
			//ѭ���ҵ���һ������С�ڴ���������֣���λ�þ��ǲ���λ��
			vec[j] = vec[j - 1];
			j--;
		}
		//��temp��ʱ�����ȥ
		vec[j] = temp;
	}
}

int main()
{
	vector<int>vec;

	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(rand() % 100);
	}
	cout << "����ǰ��";
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	SISort(vec);
	cout << "�����";
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
#endif