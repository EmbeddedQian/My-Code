#include"pch.h"

#if 0

void HillSort(vector<int>&vec)
{
	for (int gap = vec.size() / 2; gap >= 1; gap = gap / 2)		//��������
	{	
		//�ڲ�����ֱ�Ӳ�������ֻ��������������һ������һ���Ĳ������򣬶������gap��Ԫ�صĲ���
		for (int i = gap; i < vec.size(); ++i)	
		{
			for (int j = i-gap; j >= 0 && vec[j] > vec[j + gap]; j -= gap)
			{
				swap(vec[j], vec[j + gap]);
			}
		}
	}
}

/*
//������
void HillSort(vector<int>&vec)
{
	int i, j;
	int temp;
	for (int gap = vec.size() / 2; gap >= 1; gap = gap / 2)
	{
		for (i = gap; i < vec.size(); ++i)
		{
			temp = vec[i];
			j = i;
			while (j >= 0 && temp < vec[j - gap])
			{
				vec[j] = vec[j - gap];
				j -= gap;
			}
			vec[j] = temp;
			
		}
	}
}
*/
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
	HillSort(vec);
	cout << "�����";
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

#endif