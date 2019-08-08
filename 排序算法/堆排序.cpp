#include"pch.h"

#if 0
void adjust(vector<int>&vec, int len, int index)	//��������
{
	int left = 2 * index + 1;	//����
	int right = 2 * index + 2;	//�Һ���
	int maxidx = index;
	if (left < len && vec[left] > vec[maxidx])	//������Ӵ��ڸ���㣬�����ӷ��ڸ����
		maxidx = left;
	if (right < len && vec[right] > vec[maxidx])//����Һ��Ӵ��ڸ���㣬���Һ��ӷ��ڸ��ڵ�
		maxidx = right;
	if (maxidx != index)	//������������������������ˣ���˵���к��Ӵ��ڸ����
	{
		swap(vec[maxidx], vec[index]);	//���������ͽϴ��ӵ�ֵ
		adjust(vec, len, maxidx);	//�ݹ�����Խϴ��ӽ��Ϊ��������������
	}
}
void HeapSort(vector<int>&vec)
{
	for (int i = vec.size() / 2 - 1; i >= 0; i--) // ��ÿһ����Ҷ�����жѵ���
		adjust(vec, vec.size(), i);
	for (int i = vec.size() - 1; i >= 1; i--)
	{
		swap(vec[0], vec[i]); //����ǰ����λ�÷ŵ�����ĩβ
		adjust(vec, i, 0); //��δ�������Ĳ��ּ������ж���
	}
}
#endif


#if 0
void adjust(vector<int>&vec, int len)
{
	for (int start = len / 2 - 1; start >= 0; start--) //��������ÿ����Ҷ�ӽڵ�
	{
		int tmp = vec[start];	//Ҫ�����Ľ��
		int i = 0;
		for (i = 2 * start + 1; i < len; i = 2 * i + 1)//����뺢�ӵĹ�ϵ
		{
			if (i + 1 < len && vec[i] < vec[i + 1]) //�������С���Һ���
				i++;		//i++�� i���ǽϴ���Һ���
			if (vec[i] < tmp) //�ϴ�ĺ��Ӷ�С��tmp���ý���
				break;
			else  if (vec[i] > tmp) //��ʱ�ϴ�ĺ��Ӵ��ڸ�����򽫽ϴ�ĺ��Ӹ��������
				vec[start] = vec[i];
			else	//����ϴ�ĺ��ӵ�ֵ���ڸ���������κβ���
				;
			//��һ��ѭ�����start�ƶ���i�� ��Ϊ�������ֵ�ı���
			//��Ҫ�Ӹı�ĺ��ӽڵ���±����ѭ������	
			start = i;
		}
		vec[start] = tmp;//ѭ���������ҵ��˱�������������λ�ã���tmp�ŵ����ʵĸ���
	}
}




void HeapSort(vector<int>&vec)
{
	for (int i = vec.size() / 2 - 1; i >= 0; i--) // ��ÿһ����Ҷ�����жѵ���
		adjust(vec, vec.size());
	for (int i = vec.size() - 1; i >= 1; i--)
	{
		swap(vec[0], vec[i]); //����ǰ����λ�÷ŵ�����ĩβ
		adjust(vec, i); //��δ�������Ĳ��ּ������ж���
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
	HeapSort(vec);
	cout << "�����";
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

#endif

