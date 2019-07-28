// �߼����ݽṹ���㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#if 0
// BST����ʵ��
template<typename T>
class BSTree
{
public:
	BSTree() :_root(nullptr) {}

	//�ǵݹ�ʵ��BST���Ĳ������
	void noninsert(const T &val)
	{
		if (_root == nullptr)
		{
			_root = new BSTNode(val);
			return;
		}
		BSTNode *pre = nullptr;
		BSTNode *tmp = _root;
		while (tmp != nullptr)
		{
			pre = tmp;
			if (tmp->_data == val)
			{
				return;
			}
			else if (val < tmp->_data)
			{
				tmp = tmp->_left;
			}
			else 
			{
				tmp = tmp->_right;
			}
		}
		if (val < pre->_data)
		{
			pre->_left = new BSTNode(val);
		}
		else
		{
			pre->_right = new BSTNode(val);
		}
	}

	//�ݹ�ʵ��BST���Ĳ������
	void insert(const T&val)
	{
		_root = insert(_root, val);
	}

	//���ľ���ת
	void mirror()
	{
		cout << "����ת��";
		mirror(_root);
	}

	//�ǵݹ�ʵ��BST����ɾ������
	void nonmove(const T& val)
	{
		if (_root == nullptr)
		{
			return;
		}
		BSTNode*pre = nullptr;
		BSTNode*tmp = _root;
		while (tmp != nullptr)
		{
			if (val < tmp->_data)
			{
				pre = tmp;
				tmp = tmp->_left;
			}
			else if(val > tmp->_data)
			{
				pre = tmp;
				tmp = tmp->_right;
			}
			else
			{
				break;
			}
		}
		if (tmp == nullptr)
			return;
		//���Һ��Ӷ�����
		if (tmp->_left != nullptr&&tmp->_right != nullptr)
		{
			BSTNode*old = tmp;
			pre = tmp;
			while (tmp->_right != nullptr)
			{
				pre = tmp;
				tmp=tmp->_right;
			}
			old->_data = tmp->_data;
		}
		//ֻ�������ӻ����Һ��ӵ����
		//�жϺ��������ӻ����Һ���
		BSTNode*child = tmp->_left;
		if (child == nullptr)
		{
			child = tmp->_right;
		}
		//ɾ�����Ǹ����
		if (pre == nullptr)	//�����Ϊ��ʱ����ɾ�������
		{
			_root = child;
		}
		else
		{
			//Ҫ��ɾ�����ĺ��Ӹ���tmp�������Ӧ�ĵ�ַ�����
			if (tmp == pre->_left)	//���Ҫɾ���Ľ����ǰ���������� ���Ҫɾ���Ľ��ĺ�����Ϊǰ����������
			{
				pre->_left = child;
			}
			else		//����Ҫɾ���Ľ����ǰ�������Һ���
			{
				pre->_right = child;
			}
		}
		delete tmp;
	}

	//�ݹ�ʵ��BST���Ľڵ����  �������Ľڵ�ĸ���
	int numble()	
	{
		return numble(_root);
	}

	//�ݹ�ʵ��BST���ĸ߶�  �������ĸ߶�
	int leavl()		
	{
		return leavl(_root);
	}

	//ʵ��BST������ָ����Ԫ��ֵval�Ƿ����
	bool nonquery(const T &val)	
	{
		if (_root == nullptr)
		{
			return false;
		}
		BSTNode*ptmp = _root;
		while (ptmp != nullptr&&ptmp->_data != val)
		{
			if (val < ptmp->_data)
			{
				ptmp = ptmp->_left;
			}
			if (val > ptmp->_data)
			{
				ptmp = ptmp->_right;
			}
		}
		if (ptmp == nullptr)
		{
			return false;
		}
		return true;
	}

	//�ݹ�ʵ������ǰ�����
	void Pre_out()
	{
		cout << "�ݹ�ʵ��ǰ�����:";
		Pre_out(_root);
		cout << endl;
	}

	//�ݹ�ʵ�������������
	void Mid_out()
	{
		cout << "�ݹ�ʵ���������:";
		Mid_out(_root);
		cout << endl;
	}

	//�ݹ�ʵ�����ĺ������
	void Last_out()
	{
		cout << "�ݹ�ʵ�ֺ������:";
		Last_out(_root);
		cout << endl;
	}

	//�ݹ�ʵ�ֲ������
	void leavlOrder()
	{
		cout << "�ݹ�ʵ�ֲ������:";
		int l = leavl(_root);
		for(int i = 0; i < l; ++i)
		{
			leavlOrder(_root, i);
		}
		cout << endl;
	}

	//�ǵݹ�ʵ��ǰ�����
	void NonPre_Post()
	{
		cout << "�ǵݹ�ʵ��ǰ�����:";
		if (_root == nullptr)
		{
			return;
		}
		stack<BSTNode*>s;
		s.push(_root);
		while(!s.empty())
		{
			BSTNode*top = s.top();
			s.pop();
			cout << top->_data << " ";
			if (top->_right != nullptr)
			{
				s.push(top->_right);
			}
			if (top->_left != nullptr)
			{
				s.push(top->_left);
			}
		}
		cout << endl;
	}

	//�ǵݹ�ʵ���������
	void NonMid_Post()
	{
		cout << "�ǵݹ�ʵ���������:";
		if (_root == nullptr)
		{
			return;
		}
		stack<BSTNode*>s;
		BSTNode*cur = _root;
		while (!s.empty() || cur != nullptr)
		{
			if (cur != nullptr)
			{
				s.push(cur);
				cur = cur->_left;
			}
			else
			{
				BSTNode*top = s.top();
				s.pop();
				cout << top->_data << " ";

				cur = top->_right;
			}
		}
		cout << endl;
	}

	//�ǵݹ�ʵ�ֺ������
	void NonLast_Post()
	{
		cout << "�ǵݹ�ʵ�ֺ������:";
		if (_root == nullptr)
		{
			return;
		}
		stack<BSTNode*>sa;
		stack<BSTNode*>sb;
		sa.push(_root);
		while (!sa.empty())
		{
			BSTNode* top = sa.top();
			sa.pop();
			sb.push(top);
			if (top->_left != nullptr)
			{
				sa.push(top->_left);
			}
			if (top->_right != nullptr)
			{
				sa.push(top->_right);
			}
		}
		while (!sb.empty())
		{
			cout << sb.top()->_data << " ";
			sb.pop();
		}
		cout << endl;
	}

	//�ǵݹ�ʵ�ֲ����ӡ(�Ӹ��ڵ㿪ʼ��һ��һ�㰴�������ҵ�˳���ӡBST���ڵ��ֵ)
	void NonLevelOrder()
	{
		cout << "�ǵݹ�ʵ�ֲ������:";
		// 1.���_rootΪ�գ�ֱ�ӷ���
		if (_root == nullptr)
			return;
		// 2._root -> queue
		queue<BSTNode*> que;
		que.push(_root);

		// 3.ѭ���ж϶����Ƿ�Ϊ�գ� ��Ϊ��ȡ����ͷԪ�أ��ֱ��ж����Һ����Ƿ�Ϊnullptr����Ϊ��
		// ��Ҫ������ӣ�Ȼ���ӡ��ͷԪ�أ������ж���һ����ͷԪ��
		while (!que.empty())
		{
			BSTNode *front = que.front();
			cout << front->_data << " ";
			que.pop();
			if (front->_left != nullptr)
			{
				que.push(front->_left);
			}
			if (front->_right != nullptr)
			{
				que.push(front->_right);
			}
		}
		cout << endl;
	}

	//�жϵ�ǰ�������ǲ���BST��
	bool isBSTtree()
	{
		BSTNode *pre = nullptr;
		return isBSTree(_root, pre);
	}

	// �ڵ�ǰBST���У�����������[first, last]������Ԫ���ҳ�������ӡ
	void findAreaData(int first, int last)
	{
		vector<int>vec;
		findAreaData(_root, first, last, vec);
		for (int v : vec)
		{
			cout << v << " ";
		}
		cout << endl;
	}

	// ��ȡ�����ڵ������������Ƚڵ�
	int getLCA(int val1, int val2)
	{
		return getLCA(_root, val1, val2);
	}

	// ��ȡ�������������k���ڵ��ֵ
	int getLastKValue(int k) // LVR    RVL
	{
		int i = 0;
		BSTNode *p = getLastKValue(_root, k, i);
		if (p != nullptr)
		{
			return p->_data;
		}
		else
		{
			throw "no last k value, k is invalid!";
		}
	}

	// �жϲ���tree�Ƿ��ǵ�ǰBST����һ���������Ƿ���true�����򷵻�false
	bool isChildTree(const BSTree<T> &tree)
	{
		bool isChildTree(const BSTree<T> &tree)
		{
			if (_root == nullptr)
				return false;
			BSTNode *cur = _root;
			while (cur != nullptr)
			{
				if (tree._root->_data > cur->_data)
				{
					cur = cur->_right;
				}
				else if (tree._root->_data < cur->_data)
				{
					cur = cur->_left;
				}
				else
				{
					break;
				}
			}
			if (cur == nullptr)
				return false;

			return isChildTree(cur, tree._root);
		}
	}

	// ��֪һ��BST����ǰ��������pre���飬������������in���飬�ؽ�������
	void rebuildBSTree(int pre[], int len1, int in[], int len2)
	{
		this->_root = rebuildBSTree(pre, 0, len1 - 1, in, 0, len2 - 1);
	}

	//�ݹ�ʵ�ֲ���val��ֵ���ҵ�����true�����򷵻�false��
	bool query(const T val)
	{
		return query(_root, val);
	}

	//ɾ��һ��ֵΪvalue�Ľ��
	void remove(const T val)
	{
		remove(_root, val);
	}
private:

	// ����BST���ڵ������
	struct BSTNode
	{
		BSTNode(T data = T())
			:_data(data)
			, _left(nullptr)
			, _right(nullptr)
		{}
		T _data;
		BSTNode *_left;
		BSTNode *_right;
	};

	BSTNode *_root; // ָ�����ĸ��ڵ�

	//������nodeΪ���ڵ�������Ľڵ�ĸ���
	int numble(BSTNode *node)	
	{
		if (node == nullptr)
		{
			return 0;
		}
		return 1 + numble(node->_left) + numble(node->_right);
	}

	//������nodeΪ���ڵ�������ĸ߶�
	int leavl(BSTNode *node)	
	{
		if (node == nullptr)
		{
			return 0;
		}
		int h = leavl(node->_left) >= leavl(node->_right) ? leavl(node->_left) : leavl(node->_right);
		return h + 1;
	}

	//�ݹ�ǰ�����
	void Pre_out(BSTNode *node)	
	{
		if (node != nullptr)
		{
			cout << node->_data << " ";
			Pre_out(node->_left);
			Pre_out(node->_right);
		}
	}

	//�ݹ��������
	void Mid_out(BSTNode *node)	
	{
		if (node != nullptr)
		{
			Mid_out(node->_left);
			cout << node->_data << " ";
			Mid_out(node->_right);
		}
	}

	//�ݹ�������
	void Last_out(BSTNode *node)	
	{
		if (node != nullptr)
		{
			Last_out(node->_left);
			Last_out(node->_right);
			cout << node->_data << " ";
		}
	}

	//�ݹ�ʵ�ֲ������
	void leavlOrder(BSTNode *node, int l)
	{
		if (node != nullptr)
		{
			if(l==0)
			{ 
				cout << node->_data << " ";
				return;
			}
			leavlOrder(node->_left, l - 1);
			leavlOrder(node->_right, l - 1);
		}
	}

	//���ľ���ת
	void mirror(BSTNode *node)
	{
		if (node == nullptr)
			return;

		BSTNode *ptmp = node->_left;
		node->_left = node->_right;
		node->_right = ptmp;

		mirror(node->_left);
		mirror(node->_right);
	}

	//�ж�һ���������ǲ���BST��
	bool isBSTree(BSTNode *node,BSTNode *&pre)	//���������� 
	{
		if (node == nullptr)
		{
			return true;
		}

		if (!isBSTree(node->_left, pre))
		{
			return false;
		}

		if (pre != nullptr)
		{
			if (node->_data < pre->_data)
			{
				return false;
			}
		}
		pre = node;
		return isBSTree(node->_right, pre);
	}

	//��nodeΪ���ڵ�Ѱ��first��last�����Ԫ��
	void findAreaData(BSTNode *node, int first, int last, vector<int>&vec)
	{
		if (node == nullptr)
		{
			return;
		}

		findAreaData(node->_left, first, last, vec);

		if (node->_data > last)
		{
			return;
		}
		if (node->_data <= last&&node->_data >= first)
		{
			vec.push_back(node->_data);
		}

		findAreaData(node->_right, first, last, vec);
	}

	// ��ȡ�����ڵ������������Ƚڵ�
	int getLCA(BSTNode*node, int val1, int val2)
	{
		if (node == nullptr)
		{
			throw("error");
		}
		if (node->_data > val1 && node->_data > val2)
		{
			return getLCA(node->_left, val1, val2);
		}
		else if (node->_data < val1 && node->_data < val2)
		{
			return getLCA(node->_right, val1, val2);
		}
		else
		{
			return node->_data;
		}
	}

	// LVR RVL ��nodeΪ���ڵ㣬�ҷ�����������ĵ�K���ڵ�
	BSTNode* getLastKValue(BSTNode *node, int k, int &i)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		BSTNode *p1 = getLastKValue(node->_right, k, i); // R
		if (p1 != nullptr)
		{
			return p1;
		}

		i++;
		if (k == i)
		{
			return node; // V
		}

		return getLastKValue(node->_left, k, i); // L
	}

	// �ж��Ƿ��ǵ�ǰ������������father�ڵ㿪ʼ�жϣ��Ƿ�ȫ����child�Ľڵ�
	bool isChildTree(BSTNode *father, BSTNode *child)
	{
		if (father == nullptr && child == nullptr)
		{
			return true;
		}

		if (father == nullptr)
		{
			return false;
		}

		if (child == nullptr)
		{
			return true;
		}

		if (father->_data != child->_data)
		{
			return false;
		}

		return isChildTree(father->_left, child->_left)
			&& isChildTree(father->_right, child->_right);
	}

	//�ؽ�������
	BSTNode* rebuildBSTree(int pre[], int i, int j, int in[], int m, int n)
	{
		if (i > j || m > n)
		{
			return nullptr;
		}

		BSTNode *root = new BSTNode(pre[i]);
		for (int k = m; k <= n; ++k)
		{
			if (pre[i] == in[k]) // ����������ҵ����ڵ���
			{
				root->_left = rebuildBSTree(pre, i + 1, i + (k - m), in, m, k - 1);
				root->_right = rebuildBSTree(pre, i + (k - m) + 1, j, in, k + 1, n);
				break;
			}
		}
		return root;
	}

	//�ݹ�ʵ�ֲ���һ�����Ƿ���BST���Ľ��
	bool query(BSTNode*node, const T &val)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (node->_data > val)
		{
			return query(node->_left, val);
		}
		else if (val > node->_data)
		{
			return query(node->_right, val);
		}
		else return true;
	}

	//ɾ��һ��ֵΪvalue�Ľ��
	BSTNode* remove(BSTNode *node, const T &val)
	{
		if (node == nullptr)
			return nullptr;

		if (node->_data > val)
		{
			node->_left = remove(node->_left, val);
		}
		else if (node->_data < val)
		{
			node->_right = remove(node->_right, val);
		}
		else
		{
			if (node->_left != nullptr && node->_right != nullptr)
			{
				BSTNode *pre = node->_left;
				while (pre->_right != nullptr)
				{
					pre = pre->_right;
				}
				node->_data = pre->_data;
				// ֱ��ɾ��ǰ��
				node->_left = remove(node->_left, pre->_data);
			}
			else
			{
				if (node->_left != nullptr)
				{
					BSTNode *left = node->_left;
					delete node;
					return left;
				}
				else if (node->_right != nullptr)
				{
					BSTNode *right = node->_right;
					delete node;
					return right;
				}
				else
				{
					delete node;
					return nullptr;
				}
			}
		}
		return node;
	}

};

int main()
{
	//				40

	//		20				65
	//	10		25		45		70

	BSTree<int>bst;
	bst.noninsert(40);
	bst.noninsert(20);
	bst.noninsert(65);
	bst.noninsert(25);
	bst.noninsert(45);
	bst.noninsert(70);
	bst.noninsert(10);
	bst.noninsert(99);

	cout << "ɾ��ǰ:";
	bst.NonLevelOrder();
	cout << endl;

	cout << "ɾ����:";
	bst.nonmove(99);
	bst.NonLevelOrder();


	cout << "�����:" << bst.numble() << endl;
	cout << "�Ƿ����70��" << bst.nonquery(70) << endl;
	cout << "�߶�:" << bst.leavl() << endl;

	bst.Pre_out();
	bst.NonPre_Post();
	cout << endl;

	bst.Mid_out();
	bst.NonMid_Post();
	cout << endl;

	bst.Last_out();
	bst.NonLast_Post();
	cout << endl;

	bst.leavlOrder();
	bst.NonLevelOrder();
	cout << endl;


	if (bst.isBSTtree())
	{
		cout << "��һ��BST��" << endl;
	}
	else
	{
		cout << "����һ��BST��" << endl;
	}

	bst.findAreaData(25,66);
	bst.mirror();
	bst.NonLevelOrder();
	bst.mirror();
	bst.NonLevelOrder();

	int LCA = bst.getLCA(25, 45);
	cout << "LCA:" << LCA << endl;
	cout << "�Ƿ����70��" << bst.query(70) << endl;
	
	cout << "������N����:" << bst.getLastKValue(2) << endl;

	cout << endl;
	cout << "�ؽ�������" << endl;
	int pre[] = { 40,20,10,25,60,50,70 }; // VLR
	int in[] = { 10,20,25,40,50,60,70 }; // LVR
	BSTree<int> bst1;
	bst1.rebuildBSTree(pre, sizeof(pre) / sizeof(pre[0]),
		in, sizeof(in) / sizeof(in[0]));
	bst1.Pre_out();
	bst1.Mid_out();
	bst1.remove(40);
	bst1.Pre_out();
	bst1.Mid_out();
	return 0;
}

#endif
