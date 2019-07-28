#include"AfxStd.h"
#include"DuLinkList.h"

typedef int ElemType;
typedef struct DuLNode
{
	DuLNode *prev;
	DuLNode *next;
	ElemType data;
}DuLNode;

typedef struct
{
	DuLNode *head;
	int size;
}DuList;

DuLNode * Buynode(DuLNode *pr, DuLNode *nt)   //�����ڵ�
{
	DuLNode *s = (DuLNode*)malloc(sizeof(DuLNode));
	if (NULL == s) exit(1);
	s->prev = (pr == NULL) ? s : pr;
	s->next = (nt == NULL) ? s : nt;
	return s;
}
void Freenode(DuLNode *p)     //�ͷŽڵ�
{
	free(p);
}

void InitDuList(DuList &Lt)   //��ʼ������
{
	Lt.size = 0;
	Lt.head = Buynode(Lt.head->next,Lt.head->prev);
}
void DestroyDuList(DuList &Lt)
{
	Lt.head->next = Lt.head->prev;
	Lt.head->prev = Lt.head->next;
	Lt.size = 0;
}
void Insert_Item_Prev(DuList &Lt, DuLNode *ptr, ElemType x)  //������ĳ�����ǰ����ĳ��ֵ
{
	ptr->prev = Buynode(ptr->prev, ptr);
	ptr = ptr->prev;
	ptr->prev->next = ptr; // 4;
	ptr->data = x;
	Lt.size += 1;
}
void Push_Back(DuList &Lt, ElemType x)    //β����ĳ��ֵ
{
	Insert_Item_Prev(Lt, Lt.head, x);
}
void Push_Front(DuList &Lt, ElemType x)   //ͷ����ĳ��ֵ
{
	Insert_Item_Prev(Lt, Lt.head->next, x);
}
void Insert(DuList &Lt, int size, ElemType x)  //�����ض������ĵ�ĳ��ֵ
{
	for (int i = 0; i < size; i++)
	{
		Push_Front(Lt, x);
	}
}
void Insert_Array(DuList &Lt, ElemType *first, ElemType *last)   //��������
{
	if (NULL == first || NULL == last)
		return;
	for (; first != last; ++first)
	{
		Insert_Item_Prev(Lt, Lt.head, *first);
	}
}
DuLNode *FindValue(DuList &Lt, ElemType x)   //����ֵΪx�Ľ�� ���ҷ���
{
	if (Lt.head->next = Lt.head->prev)
		return;
	DuLNode *p = Lt.head->next;
	while (p->data != x &&p != Lt.head)
	{
		p = p->next;
	}
	if (p == Lt.head)
	{
		p = NULL;
	}
	return p;
}
DuLNode *FindPos(DuList &Lt, int pos)     //����posλ�õĽ�� ��λ��ɾ��
{
	if (pos<1 || pos>Lt.size) return NULL;
	DuLNode *p = Lt.head->next;
	int i = 1;
	while (i < pos)
	{
		++i;
		p = p->next;
	}
	return p;
}
void EarseDulist(DuList &Lt, DuLNode*ptr)  //�����ɾ��
{
	assert(NULL == ptr);
	ptr->next->prev = ptr->prev;
	ptr->prev->next = ptr->next;
	Freenode(ptr);
	Lt.size -= 1;
}
bool EmptyDulist(DuList&Lt)    //˫�����п�
{
	return Lt.size == 0;
}
void Pop_Front(DuList &Lt)    //ͷɾԪ��
{
	if (EmptyDulist(Lt)) return;
	EarseDulist(Lt, Lt.head->next);
}
void Pop_Back(DuList &Lt)     //βɾԪ��
{
	if (EmptyDulist(Lt)) return;
	EarseDulist(Lt, Lt.head->prev);
}
void EarsePos(DuList &Lt, int pos)  //��λ��ɾ��
{
	DuLNode *p = FindPos(Lt, pos);

}
void Remove(DuList&Lt, ElemType x) //ɾ��˫������ֵΪx������ֵ��
{
	while (NULL == Lt.head)
	{
		return;
	}
	DuLNode *p = Lt.head->next;
	while (Lt.head != p)
	{
		while (p->data = x)
		{
			DuLNode *q = p;
			EarseDulist(Lt, q);
		}
		p = p->next;
	}
}
void Swap(DuLNode *a, DuLNode *b)   //�������
{
	DuLNode*tmp= a;
	a = b;
	b = tmp;
}
void ReverseDulist(DuList &Lt)     //����˫����
{
	while (NULL == Lt.head)
	{
		return;
	}
	while (Lt.size > 2)
	{
		DuLNode *p = Lt.head->next;
		while (Lt.head != p)
		{
			DuLNode *s = p;
			p = p->next;
			Swap(p->next,p->prev);
		}
	}
	Swap(Lt.head->next,Lt.head->prev);
}
