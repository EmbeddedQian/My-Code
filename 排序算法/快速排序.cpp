#include"pch.h"

#if 0
int Partition(vector<int>&vec, int low, int high)
{
	//����ȡ�� �õ���Ŧ
	int pivotkey;
	int m = low + (high - low) / 2;	//���������м�Ԫ���±�
	if (vec[low] > vec[high])	//high��
		swap(low, high);
	if (vec[m] > vec[high])		//high���
		swap(m, high);
	if (vec[m] > vec[low])		//�ڶ����м��
		swap(m, low);	//��ʱvec[low]�Ѿ�Ϊ�������������������ؼ��ֵ��м�ֵ��

	pivotkey = vec[low];	//���м�ֵ������Ŧ
	
	int temp = pivotkey;
	while (low < high)	//ֻҪhigh����low��low��high��λ�û�û���غϻ򽻻�
	{
		//�����λ����������Ŧֵ�����ı䣬��λ�±����¼�
		//����С�ڵĻ�����Ŧֵ�͸�λ��С����������
		while (low<high&&vec[high]>pivotkey)	
		{
			high--;
		}
		//swap(vec[low], vec[high]);
		vec[low] = vec[high];	//�滻����֪����
		//ͬ�������λ����С����Ŧֵ�����ı䣬��λ�±����ϼ�
		//������ڵĻ�����Ŧֵ�͵�λ�Ĵ��������
		while (low < high&&vec[low] < pivotkey)	
		{
			low++;
		}
		//swap(vec[high], vec[low]);		
		vec[high] = vec[low];	//�滻����֪����
		//һֱ��ĳ��ʱ�̵�λ��С�ڸ�λ����˵���Ѿ���������
		//��Ŧֵ�����ȫ��С����Ŧֵ����Ŧֵ���ұ�ȫ��������Ŧֵ
	}
	vec[low] = temp;
	return low;	//���ش�ʱ��Ŧֵ��λ���±�
}

void QuickSort(vector<int>&vec,int low,int high)
{
	int pivot;	//��Ŧλ��
	if (low < high)
	{
		pivot = Partition(vec, low, high);	//�ҵ���Ŧλ��
		QuickSort(vec, low, pivot - 1);		//�ݹ�С����Ŧֵ�Ĳ���
		low = pivot + 1;
		//QuickSort(vec, pivot + 1, high);	//�ݹ������Ŧֵ�Ĳ���
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
	QuickSort(vec,0,vec.size()-1);
	cout << "�����";
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

#endif