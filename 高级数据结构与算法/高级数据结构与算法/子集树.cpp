#include"stdafx.h"


//�˻ʺ�����
#if 0
//�˻ʺ�����
const int N = 8;
int ar[] = { 1,2,3,4,5,6,7,8 }; // �����index����������
int mycount = 0;

void swap(int i, int j)
{
	int tmp = ar[i];
	ar[i] = ar[j];
	ar[j] = tmp;
}
bool line(int i) // i��ʾ����
{
	for (int j = 0; j < i; ++j)
	{
		if (i - j == abs(ar[i] - ar[j]))
		{
			return false;
		}
	}
	return true;
}
void func(int i)
{
	if (i == N)
	{
		mycount++;
		for (int k = 0; k < N; ++k)
		{
			cout << ar[k] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int j = i; j < N; ++j)
		{
			swap(i, j);
			if (line(i)) // i��ʾ��ǰ��������������һ��λ�õ�Ԫ�أ�i��������
			{
				func(i + 1);
			}
			swap(i, j);
		}
	}
}
int main()
{
	func(0);
	cout << mycount << endl;
	return 0;
}

//�˻ʺ�ʾ��
/*
static int gEightQueen[8] = { 0 }, gCount = 0;
void print()//���ÿһ������������лʺ�İڷ����
{
	for (int i = 0; i < 8; i++)
	{
		int inner;
		for (inner = 0; inner < gEightQueen[i]; inner++)
			cout << "0 ";
		cout << "# ";
		for (inner = gEightQueen[i] + 1; inner < 8; inner++)
			cout << "0 ";
		cout << endl;
	}
	cout << "==========================\n";
}
int check_pos_valid(int loop, int value)//����Ƿ�����ж���ʺ���ͬһ��/��/�Խ��ߵ����
{
	int index;
	int data;
	for (index = 0; index < loop; index++)
	{
		data = gEightQueen[index];
		if (value == data)
			return 0;
		if ((index + data) == (loop + value))
			return 0;
		if ((index - data) == (loop - value))
			return 0;
	}
	return 1;
}
void eight_queen(int index)
{
	int loop;
	for (loop = 0; loop < 8; loop++)
	{
		if (check_pos_valid(index, loop))
		{
			gEightQueen[index] = loop;
			if (7 == index)
			{
				gCount++, print();
				gEightQueen[index] = 0;
				return;
			}
			eight_queen(index + 1);
			gEightQueen[index] = 0;
		}
	}
}
int main(int argc, char*argv[])
{
	eight_queen(0);
	cout << "total=" << gCount << endl;
	return 0;
}
*/

#endif

//������
#if 0
//������
//��������ʱ�临�Ӷ�ΪO(n!) 4x3x2x1; 
int ar[] = { 1,2,3 };
const int N = 3;

void swap(int i, int j)
{
	int tmp = ar[i];
	ar[i] = ar[j];
	ar[j] = tmp;
}

void func(int i)
{
	if (i == N)		//�ҵ�Ҷ�ӽڵ���
	{
		for (int k = 0; k < N; ++k)
		{
			cout << ar[k] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int j = i; j < N; ++j)
		{
			swap(i, j);
			func(i + 1);
			swap(i, j);
		}
	}
}
int main()
{
	func(0);
	return 0;
}
#endif

//�ִ�װ������
#if 0
/*
װ�����⣺�����ִ��������ֱ���c1��c2����ôװ����Ʒ��
�ܹ�ʹ��Ʒ��װ���ִ�����
*/
const int N = 7;
int w[] = { 7,8,5,9,4,6,3 };
int c1 = 22;
int c2 = 20;

int x[N];
int cw;
int bestw;
int bestx[N];
int r;
void func(int i)
{
	if (i == N)
	{
		if (cw > bestw)
		{
			bestw = cw;
			for (int j = 0; j < N; ++j)
			{
				bestx[j] = x[j];
			}
		}
	}
	else
	{
		r -= w[i];
		if (cw + w[i] <= c1) // i�ڵ��������ļ�֦����
		{
			cw += w[i];
			x[i] = 1;
			func(i + 1);
			cw -= w[i];
		}

		if (cw + r > bestw)  // i�ڵ��������ļ�֦����
		{
			x[i] = 0;
			func(i + 1);
		}
		r += w[i];
	}
}
int main()
{
	for (int w1 : w)
	{
		r += w1;
	}
	func(0);
	cout << "�ִ�c1:" << c1 << "װ�����Ʒ��:";
	for (int i = 0; i < N; ++i)
	{
		if (bestx[i] == 1)
		{
			cout << w[i] << " ";
		}
	}
	cout << endl;
	cout << "�ִ�c2:" << c2 << "װ�����Ʒ��:";
	for (int i = 0; i < N; ++i)
	{
		if (bestx[i] == 0)
		{
			cout << w[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
#endif

//0 - 1��������
#if 0
/*
0-1��������
��������һ����Ʒ�����ǵ������ͼ�ֵ�ֱ���
w={w1,w2,w3,w4,w5...}
v={v1,v2,v3,v4,v5...}
������һ��������������Ϊc,�������װ����Ʒ���ܹ�ʹ������ֵ��󻯣�
*/
const int N = 5;
int w[] = { 8,4,9,6,7 };
int v[] = { 7,9,6,12,3 };
int c = 18;

int x[N]; // ��������
int bestx[N]; // ��¼�����Ӽ�������
int cw; // ��¼ѡ�����Ʒ������
int cv; // ��¼ѡ����Ʒ�ļ�ֵ
int r; // ��¼�ڵ���������ʣ���ܹ�ѡ�����Ʒ���ܼ�ֵ
int bestv = 0; // ��¼ѡ�����Ʒ�����ż�ֵ

// �������ѡ�����Ʒ������ֵ
void func(int i)
{
	if (i == N)
	{
		if (cv > bestv)
		{
			bestv = cv;
			for (int j = 0; j < N; ++j)
			{
				bestx[j] = x[j];
			}
		}
	}
	else
	{
		r -= v[i];
		if (cw + w[i] <= c) // i�ڵ��������ļ�֦����
		{
			cw += w[i];
			cv += v[i];
			x[i] = 1;
			func(i + 1);
			cw -= w[i];
			cv -= v[i];
		}

		if (cv + r > bestv)  // i�ڵ��������ļ�֦����
		{
			x[i] = 0;
			func(i + 1);
		}
		r += v[i];

		/*if (cw + w[i] <= c)
		{
			cw += w[i];
			cv += v[i];
			x[i] = 1;
			func(i + 1);
			cw -= w[i];
			cv -= v[i];
		}
		x[i] = 0;
		func(i + 1);*/
	}
}
int main()
{
	for (int v1 : v)
	{
		r += v1;
	}
	func(0);
	cout << "best value:" << bestv << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << bestx[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif



//�Ӽ���
#if 0
/*
12 3 45 6 78 9 43 22 62 31
��һ����������ѡ��һ����������ʹѡ��������ĺͣ���ʣ�µ������ĺ͵Ĳ���С
��һ��2n����������ѡ��n��������ʹѡ��������ĺͣ���ʣ�µ������ĺ͵Ĳ���С
*/

int ar[] = { 12,3,45,6,78,9,43,22,62,31 };
const int N = 10;
int x[N]; // �Ӽ��������ĸ�������
int bestx[N]; // ��¼���Ž���Ӽ�
int sum; // ��¼��ѡ�Ӽ����ֵĺ�
int r; // ��¼δѡ������ֵĺ�
int cnt; // ��¼ѡ����Ӽ��ĸ���
unsigned int Min = 0xFFFFFFFF;

int mycount = 0;

void func(int i)
{
	if (i == N)
	{
		mycount++;

		if (cnt != N / 2)
			return;

		int ret = abs(sum - r);
		if (Min > ret)
		{
			Min = ret;
			for (int j = 0; j < N; ++j)
			{
				bestx[j] = x[j];
			}
		}
	}
	else
	{
		if (cnt < N / 2)	//��֦����
		{
			r -= ar[i];
			sum += ar[i];
			cnt++;				//if(cnt < N/2)
			x[i] = 1;
			func(i + 1);
			cnt--;
			sum -= ar[i];
			r += ar[i];
			x[i] = 0;
			func(i + 1);
		}
	}
}
int main()
{
	for (int val : ar)
		r += val;
	func(0);

	cout << "min:" << Min << endl;
	for (int i = 0; i < N; ++i)
	{
		if (bestx[i] == 1)
		{
			cout << ar[i] << " ";
		}
	}
	cout << endl;
	cout << "mycount:" << mycount << endl;

	return 0;
}
#endif