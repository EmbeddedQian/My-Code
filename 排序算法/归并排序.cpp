#include"pch.h"

#if 0

void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	//���м�ֿ� i++һֱ��midindex��j++һֱ����endindex
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		//�ֱ�Ƚ��������ݶ�Ӧλ�õ����ֵĴ�С���ҳ�С�����֣����븨������
		if (sourceArr[i] > sourceArr[j])
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	//��������һ���������ȫ�����븨�������ʣ���µ�����һ�������е�Ԫ��ȫ�����η��븨������
	while (i != midIndex + 1)	//�ж����ĸ����ֻ�ʣ������
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	//�����������е�Ԫ��ȫ������ԭ������
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}

//�ڲ�ʹ�õݹ�
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)	//�ָʣ����Ԫ�ػ���һ��Ԫ������Ҳ���ɷָ�������
	{
		//�ҵ��м�λ�ý��з���
		midIndex = startIndex + (endIndex - startIndex) / 2;	//�������int
		//�ֱ�Էָ�Ĳ��ֽ��еݹ�ָ�
		MergeSort(sourceArr, tempArr, startIndex, midIndex);
		MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
		//���ָ��������кϲ�
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	}
}

int main()
{
	int a[8] = { 50, 10, 20, 30, 70, 40, 80, 60 };
	int i, b[8];
	MergeSort(a, b, 0, 7);
	for (i = 0; i < 8; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

#endif