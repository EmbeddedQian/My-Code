

// C++maze 20190319.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"stdafx.h"
/*
��OOP���һ���Թ�·���Ĳ�������
����������£�
�����Թ��Ĵ�С(�� ��): 5 5
���������Թ���·����Ϣ(0��ʾ�����ߣ�1��ʾ������)��
0 0 1 0 0
0 0 0 0 0
1 1 0 1 1
0 1 0 1 0
0 0 0 0 0
��ʼѰ���Թ�·����Ϣ��...

��ӡ���Թ������ڿ�ͨ�е�·��

* * 1 0 0
0 * * 0 0
1 1 * 1 1
0 1 * 1 0
0 0 * * *
*/

const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;
const int OK = 4;
const int ERR = 5;
/*
// �����Թ�·���ڵ�
class MazeNode
{
public:
MazeNode() {}
MazeNode(int x, int y) :mx(x), my(y)
{
for (int i = 0; i < 4; ++i)
{
mway[i] = OK;
}
}


int getstate(int x) { return mway[x]; }
int getmval() { return mval; }
int getX() { return mx; }
int getY() { return my; }

void setWayState(int x, int state) { mway[x] = state; }
void setmval(int val) { mval = val; }
void setmx(int x) { mx = x; }
void setmy(int y) { my = y; }

private:
int mval;
int mx;
int my;
int mway[4];
};
// �����ڴ��������˳��ջ
class CStack
{
public:
CStack(int size = 10) :msize(size), mtop(-1)
{
mpStack = new MazeNode[size];
}

~CStack()
{
delete[]mpStack;
mpStack = nullptr;     //NULL<=>0  ָ�����nullptr
}

void push(MazeNode val)   //ѹջ
{
if (full())
{
if (!resize())
{
cout << "resize error" << endl;
return;
}
}
mpStack[++mtop] = val;
}
void pop()  //��ջ
{
if (empty())
{
return;
}
--mtop;
}
MazeNode top()const
{
if (empty())
{
throw"stack empty!";
}
return mpStack[mtop];
}
bool full()const
{
return mtop + 1 == msize;
}
bool empty()const
{
return mtop == -1;
}
private:
MazeNode *mpStack;
int mtop;
int msize;
bool resize()  // ��ԭ��2���Ĵ�С��չջ�ռ�
{
MazeNode *newdata = new MazeNode[msize * 2];
if (NULL == newdata)
{
return false;
}
for (int i = 0; i < msize; i++)
{
newdata[i] = mpStack[i];
}
delete[]mpStack;
mpStack = newdata;
msize *= 2;
return true;
}
};
// ==========================================================���������Թ�
class Maze
{
public:
Maze(int _mrow = 0, int _mcol = 0) :mrow(_mrow), mcol(_mcol)
{
mpcells = new MazeNode*[mrow];
for (int i = 0; i < mrow; ++i)
{
mpcells[i] = new MazeNode[mcol];
}
}
void setMazeNode(int val, int x, int y)//����ĳ�����ֵ
{
mpcells[x][y].setmval(val);
mpcells[x][y].setmx(x);
mpcells[x][y].setmy(y);
}
void setMazeNodeState()//����ĳ����ĳ������ķ���״̬
{
for (int i = 0; i < mrow; ++i)
{
for (int j = 0; j < mcol; ++j)
{
if (mpcells[i][j].getmval() == 1)
{
continue;
}
if (i == 0)
{
mpcells[i][j].setWayState(UP, ERR); //��һ��
}
if (j == 0)
{
mpcells[i][j].setWayState(LEFT, ERR);//��һ��
}
if (i == mrow - 1)
{
mpcells[i][j].setWayState(DOWN, ERR);//���һ��
}
if (j == mcol - 1)
{
mpcells[i][j].setWayState(RIGHT, ERR);//���һ��
}
if (i > 0 && mpcells[i - 1][j].getmval() == 1)
{
mpcells[i][j].setWayState(UP, ERR);//�ϱ߲�����
}
if (i < mrow - 1 && mpcells[i + 1][j].getmval() == 1)
{
mpcells[i][j].setWayState(DOWN, ERR);//�±߲�����
}
if (j > 0 && mpcells[i][j - 1].getmval() == 1)
{
mpcells[i][j].setWayState(LEFT, ERR);//��߲�����
}
if (j < mcol - 1 && mpcells[i][j + 1].getmval() == 1)
{
mpcells[i][j].setWayState(RIGHT, ERR);//�ұ߲�����
}
}
}
}
void findMazePath()
{
if (mpcells[0][0].getmval() == 1)
{
return;
}
mstack.push(mpcells[0][0]);
while (!mstack.empty())
{
MazeNode top = mstack.top();
int x = top.getX();
int y = top.getY();
if (x == mrow - 1 && y == mcol - 1)
{
return;
}
// ���ҷ�����
if (mpcells[x][y].getstate(RIGHT) == OK)
{
mpcells[x][y].setWayState(RIGHT, ERR);
mpcells[x][y + 1].setWayState(LEFT, ERR);
mstack.push(mpcells[x][y + 1]);
continue;
}
// ���·�����
if (mpcells[x][y].getstate(DOWN) == OK)
{
mpcells[x][y].setWayState(DOWN, ERR);
mpcells[x + 1][y].setWayState(UP, ERR);
mstack.push(mpcells[x + 1][y]);
continue;
}
// ��������
if (mpcells[x][y].getstate(LEFT) == OK)
{
mpcells[x][y].setWayState(LEFT, ERR);
mpcells[x][y - 1].setWayState(RIGHT, ERR);
mstack.push(mpcells[x][y - 1]);
continue;
}
// ���Ϸ�����
if (mpcells[x][y].getstate(UP) == OK)
{
mpcells[x][y].setWayState(UP, ERR);
mpcells[x - 1][y].setWayState(DOWN, ERR);
mstack.push(mpcells[x - 1][y]);
continue;
}
mstack.pop();
}
}
void showResult()
{
if (mstack.empty())
{
cout << "���Թ������ڿ�ͨ�е�·��" << endl;
return;
}
while (!mstack.empty())
{
MazeNode node = mstack.top();
mpcells[node.getX()][node.getY()].setmval('*');
mstack.pop();
}

for (int i = 0; i < mrow; i++)
{
for (int j = 0; j < mcol; j++)
{
if (mpcells[i][j].getmval() == '*')
{
cout << "*" << " ";
}

else
{
cout << mpcells[i][j].getmval() << " ";
}
}
cout << endl;
}
}

private:
int mcol;
int mrow;
MazeNode **mpcells;
CStack mstack;
};
*/
class MazeNode
{
public:
	MazeNode()
	{
		// �ȳ�ʼ���Թ�·�����ĸ�����Ϊ������״̬
		for (int i = 0; i < 4; ++i)
		{
			mway[i] = OK;//��ʼ���ѽ����ĸ���������Ϊ��״̬
		}
	}
	int getVal() { return mval; }
	int getX() { return mx; }
	int getY() { return my; }
	int getWayState(int way) { return mway[way]; }

	void setWayState(int way, int state) { mway[way] = state; }//���÷���״̬
	void setVal(int val) { mval = val; }
	void setX(int x) { mx = x; }
	void setY(int y) { my = y; }
private:
	int mval;
	int mx;
	int my;
	int mway[4];
};
// �����ڴ��������˳��ջ
class Stack
{
public:
	// ��Ա�����������ľ��ǳ�Ա����
	Stack(int size = 10)
		:mtop(-1), msize(size)
	{
		mpStack = new MazeNode[msize];
	}
	~Stack()
	{
		delete[]mpStack;
		mpStack = nullptr;
	}
	void push(MazeNode &p)
	{
		if (this->full())
			this->resize();
		mpStack[++mtop] = p;
	}
	void pop()
	{
		if (this->empty())
			return;
		this->mtop--;
	}
	MazeNode top()const
	{
		if (empty())
			throw"";
		return this->mpStack[this->mtop];
	}
	bool full()const { return this->mtop == this->msize - 1; }
	bool empty()const { return this->mtop == -1; }
private:
	MazeNode *mpStack; // ���ջ��Ԫ��
	int mtop; // ջ��ָ��
	int msize; // ջ���ܳ���
	void resize()
	{
		MazeNode* ptemp = new MazeNode[msize * 2];
		for (int i = mtop; i >= 0; i--)
		{
			ptemp[i] = mpStack[i];
		}
		delete[]mpStack;
		mpStack = ptemp;
		msize *= 2;
	}
};

// ���������Թ�
class Maze
{
public:
	Maze(int r, int c)
		:mrow(r), mcol(c)
	{
		mpcells = new MazeNode*[mrow];
		for (int i = 0; i < mrow; ++i)
		{
			mpcells[i] = new MazeNode[mcol];
		}
	}
	~Maze()
	{
		for (int i = 0; i < mrow; ++i)
		{
			delete[]mpcells[i];
		}
		delete[]mpcells;
		mpcells = nullptr;
	}
	void setMazeNode(int val, int i, int j)
	{
		mpcells[i][j].setVal(val);
		mpcells[i][j].setX(i);
		mpcells[i][j].setY(j);
	}
	void setMazeNodeState()
	{
		for (int i = 0; i < mrow; ++i)
		{
			for (int j = 0; j < mcol; ++j)
			{
				if (mpcells[i][j].getVal() == 1)//���ֵΪ1 ˵��������
				{
					continue;
				}
				if (i == 0)//˵���ǵ�һ����������Ϸ�����Ϊ������
				{
					mpcells[i][j].setWayState(UP, ERR);
				}
				if (j == 0)//˵���ǵ�һ���������������Ϊ������
				{
					mpcells[i][j].setWayState(LEFT, ERR);
				}
				if (i == mrow - 1)//˵�������һ����������·�����Ϊ������
				{
					mpcells[i][j].setWayState(DOWN, ERR);
				}
				if (j == mcol - 1)//˵�������һ����������ҷ�����Ϊ������
				{
					mpcells[i][j].setWayState(RIGHT, ERR);
				}
				if (i>0 && mpcells[i - 1][j].getVal() == 1)
				//���ǵ�һ���������Ϸ���[i - 1][j]��ֵΪ1����������Ϸ�����Ϊ�����ߣ�
				{
					mpcells[i][j].setWayState(UP, ERR);
				}
				if (i<mrow - 1 && mpcells[i + 1][j].getVal() == 1)
				//�������һ���������·���[i + 1][j]��ֵΪ1����������·�����Ϊ�����ߣ�
				{
					mpcells[i][j].setWayState(DOWN, ERR);
				}
				if (j>0 && mpcells[i][j - 1].getVal() == 1)
				//���ǵ�һ������������[i][j - 1]��ֵΪ1���������������Ϊ�����ߣ�
				{
					mpcells[i][j].setWayState(LEFT, ERR);
				}
				if (j<mcol - 1 && mpcells[i][j + 1].getVal() == 1)
				//�������һ���������ҷ���[i][j + 1]��ֵΪ1����������ҷ�����Ϊ�����ߣ�
				{
					mpcells[i][j].setWayState(RIGHT, ERR);
				}
			}
		}
	}
	void findMazePath()
	{
		//���Թ�����ʼ����ֵΪ1����϶��������Թ�·����
		if (mpcells[0][0].getVal() == 1)
			return;

		//����ȷ��·�����ѹ��stack�У�
		mstack.push(mpcells[0][0]);
		
		while (!mstack.empty())
		{
			MazeNode top = mstack.top();
			int x = top.getX();
			int y = top.getY();
			if (x == mrow - 1 && y == mcol - 1)//����������Թ������½����˳���
			{
				return;
			}
			//�����Լ�Ĭ����һ�����Ĳ�ѯ��������Ϊ��������
			//���ĳһ�������ұߵĵ�״̬Ϊ����
			if (mpcells[x][y].getWayState(RIGHT) == OK)
			{
				mpcells[x][y].setWayState(RIGHT, ERR);
				//�ѵ�ǰ�����ҷ�����Ϊ������ ��ʾ�Ѿ��߹�����·���Ժ�����������ԩ��·��
				//�Է�ֹ������ջ�����������·������������ѭ��
				//��ϸ�±߻ὲ
				mpcells[x][y + 1].setWayState(LEFT, ERR);
				//ͬ����ұ߽�������Ҳ��Ϊ������
				mstack.push(mpcells[x][y + 1]);
				//Ȼ����ұߵĽ�����ѹջ ѹ�뵽�Թ�����ȷ·�����ȥ
				continue;
			}
			//������������ĵ���˼�붼��ͬ���
			if (mpcells[x][y].getWayState(DOWN) == OK)
			{
				mpcells[x][y].setWayState(DOWN, ERR);
				mpcells[x + 1][y].setWayState(UP, ERR);
				mstack.push(mpcells[x + 1][y]);
				continue;
			}
			if (mpcells[x][y].getWayState(LEFT) == OK)
			{
				mpcells[x][y].setWayState(LEFT, ERR);
				mpcells[x][y - 1].setWayState(RIGHT, ERR);
				mstack.push(mpcells[x][y - 1]);
				continue;
			}
			if (mpcells[x][y].getWayState(UP) == OK)
			{
				mpcells[x][y].setWayState(UP, ERR);
				mpcells[x - 1][y].setWayState(DOWN, ERR);
				mstack.push(mpcells[x - 1][y]);
				continue;
			}
			//�ߵ���һ��˵���ý����ĸ������ǲ����ߵ� 
			//��������Ҫ��ջ��һ���ϸ��������������Ƿ����ͨ 
			//��ʱ��ص��ϸ����Ͳ�����������ķ����� 
			//��Ҫ��Ĭ��˳����ĸ��������һ������
			//��Ϊ���ǵ�ʱ�Ѿ���Ҫ�ߵ���һ�������״̬��Ϊ��������
			//����ϸ������ĸ�����Ҳ��ͨ��һֱ��ջ 
			//ֱ��ջ�� ˵��û����ȷ��ͨ���Թ�·��
			mstack.pop();
		}
	}
	void showResult()
	{
		if (mstack.empty())//�ж�·��ջ�Ƿ��
		{
			cout << "���Թ������ڿ�ͨ�е�·��" << endl;
			return;
		}
		cout << "���Թ����ڿ�ͨ�е�·��Ϊ��" << endl;
		while (!mstack.empty())//��ջ��ߵ���ȷ·����Ϣ�Ľ���ֵ������Ϊ*��
		{
			MazeNode node = mstack.top();
			mpcells[node.getX()][node.getY()].setVal('*');
			mstack.pop();
		}
		//��ӡ���Թ�
		for (int i = 0; i < mrow; ++i)
		{
			for (int j = 0; j < mcol; ++j)
			{
				if (mpcells[i][j].getVal() == '*')
				{
					cout << "*" << " ";
				}
				else
				{
					cout << mpcells[i][j].getVal() << " ";
				}
			}
			cout << endl;
		}
	}
private:
	int mcol;
	int mrow;
	MazeNode **mpcells;
	Stack mstack;
};
int main()
{
	cout << "�����Թ��Ĵ�С:";
	int row, col;
	cin >> row >> col;

	Maze maze(row, col);

	cout << "�����Թ�·����Ϣ:" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int data;
			cin >> data;  // data  [i, j]
			maze.setMazeNode(data, i, j);
		}
	}
	// ����·��������״̬��Ϣ
	maze.setMazeNodeState();

	// ��ʼѰ���Թ�·��
	maze.findMazePath();

	// ��ӡ�Թ�·����Ϣ
	maze.showResult();

	return 0;
}

