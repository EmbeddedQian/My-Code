#include"pch.h"

#if 0
void SSSort(vector<int>&vec)
{
	int i, j, min;
	for (i = 0; i < vec.size()-2; i++)
	{
		min = i;	//����ǰ�±궨��Ϊ��Сֵ�±�
		for (j = i + 1; j <= vec.size()-1; j++)		//ѭ��i֮������� 
		{
			if (vec[min] > vec[j])		//�����С�ڵ�ǰ��Сֵ�Ĺؼ���
				min = j;				//���˹ؼ��ֵ��±긳ֵ��min
		}

		if (i != min)					//��min������i,˵���ҵ���Сֵ������vec[i]��vec[min]��ֵ
		{
			swap(vec[i], vec[min]);		//����vec[i]��vec[min]��ֵ
		}
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
	SSSort(vec);
	cout << "�����";
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

#endif