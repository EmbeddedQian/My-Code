

#include"AfxStd.h"
#include"ListStack.h"

StackNode * Buynode()
{
	StackNode *s = (StackNode*)malloc(sizeof(StackNode));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(StackNode));
	return s;
}

void Freenode(StackNode *p)
{
	free(p);
}

void InitStack(LinkStack &s)  //��ʼ��
{
	s.top = NULL;
	s.size = 0;
}

void DestroyStack(LinkStack &s)
{
	ClearStack(s);
}

void ClearStack(LinkStack &s)  //���
{
	while (s.top != NULL)
	{
		StackNode *q = s.top;
		s.top = q->next;
		Freenode(q);
	}
	s.size = 0;
}

int GetSize(LinkStack &s)
{
	return s.size;
}
 
bool EmptyStack(LinkStack &s)
{
	return GetSize(s) == 0;
}

void Push(LinkStack &s, ElemType val)  //ѹջ
{
	StackNode *sp = Buynode();
	sp->data = val;
	sp->next = s.top;
	s.top = sp;
	s.size += 1;
}

bool GetTop(LinkStack &s, ElemType &e)  //��ջ��Ԫ��
{
	if (EmptyStack(s))
	{
		return false;
	}
	e = s.top->data;
	return true;
}

bool Pop(LinkStack &s, ElemType &e)   //��ջ
{
	if (EmptyStack(s))
	{
		return false;
	}
	e = s.top->data;
	StackNode *q = s.top;
	s.top = q->next;
	Freenode(q);
	s.size -= 1;
	return true;
}

