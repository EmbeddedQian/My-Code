#include"stdafx.h"


//AVL��ȱ�㣺 ��ת������ ����ʱ��Ҫ��תhight��  log n  �ʺϲ�ѯ ���ʺϲ���ɾ��

template<typename T>
class AVL
{
public:
	AVL() { _root = nullptr; }

	// �ݹ�ʵ��AVL���Ĳ������  BST + ƽ��
	void insert(const T &val)
	{
		_root = insert(_root, val);
	}

	// �ݹ�ʵ��AVL����ɾ������  BST + ƽ��
	void remove(const T &val)
	{
		_root = remove(_root, val);
	}

	// �ж�һ�� ������ �Ƿ��� ƽ��������������Ƿ���true�����򷵻�false
	bool isAVLTree()
	{
		return isAVLTree(_root);
	}

	//�ж�һ�� ���������� �Ƿ��� ƽ����
	bool isAVL()
	{
		return isAVL(_root);
	}

	//���ĸ߶�
	int level()
	{
		return level(_root);
	}

private:
	struct AVLNode
	{
		AVLNode(T data = T())
			:_data(data)
			, _left(nullptr)
			, _right(nullptr)
			, _height(1)
		{}
		T _data;
		AVLNode *_left;
		AVLNode *_right;
		int _height; // �洢�ľ��ǽڵ�ĸ߶�
	};
	// ��nodeΪ��ʼ�ڵ㣬����ֵΪval�Ľڵ�
	AVLNode* insert(AVLNode *node, const T& val)
	{
		if (node == nullptr)
		{
			return new AVLNode(val);
		}

		if (node->_data > val)
		{
			node->_left = insert(node->_left, val);
			// AVL��ӵĽڵ�ʧ���ж�
			if (height(node->_left) - height(node->_right) > 1)
			{
				if (height(node->_left->_left) >= height(node->_left->_right))
				{
					// ���ӵ�������̫��
					node = rightRotate(node);
				}
				else
				{
					// ���ӵ�������̫��
					node = leftBalance(node);
				}
			}
		}
		else if (node->_data < val)
		{
			node->_right = insert(node->_right, val);
			// AVL��ӵĽڵ�ʧ���ж�
			if (height(node->_right) - height(node->_left) > 1)
			{
				if (height(node->_right->_right) >= height(node->_right->_left))
				{
					// �Һ��ӵ�������̫��
					node = leftRotate(node);
				}
				else
				{
					// �Һ��ӵ�������̫��
					node = rightBalance(node);
				}
			}
		}
		else
		{
			;
		}

		// �ڵݹ���ݹ����У����½ڵ�ĸ߶�ֵ
		node->_height = maxHeight(node->_left, node->_right) + 1;
		return node;
	}

	// ��nodeΪ��ʼ�ڵ㣬ɾ��ֵΪval�Ľڵ�
	AVLNode* remove(AVLNode *node, const T &val)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (node->_data > val)
		{
			node->_left = remove(node->_left, val);
			if (height(node->_right) - height(node->_left) > 1)
			{
				if (height(node->_right->_right) >= height(node->_right->_left))
				{
					// �Һ��ӵ�������̫��
					node = leftRotate(node);
				}
				else
				{
					// �Һ��ӵ�������̫��
					node = rightBalance(node);
				}
			}
		}
		else if (node->_data < val)
		{
			node->_right = remove(node->_right, val);
			if (height(node->_left) - height(node->_right) > 1)
			{
				if (height(node->_left->_left) >= height(node->_left->_right))
				{
					// ���ӵ�������̫��
					node = rightRotate(node);
				}
				else
				{
					// ���ӵ�������̫��
					node = leftBalance(node);
				}
			}
		}
		else
		{
			if (node->_left != nullptr && node->_right != nullptr)
			{
				if (height(node->_left) >= height(node->_right))
				{
					// ǰ���滻
					AVLNode *pre = node->_left;
					while (pre->_right != nullptr)
					{
						pre = pre->_right;
					}
					node->_data = pre->_data;
					node->_left = remove(node->_left, pre->_data);
				}
				else
				{
					// ����滻
					AVLNode *post = node->_right;
					while (post->_left != nullptr)
					{
						post = post->_left;
					}
					node->_data = post->_data;
					node->_right = remove(node->_right, post->_data);
				}
			}
			else
			{
				if (node->_left != nullptr)
				{
					AVLNode *left = node->_left;
					delete node;
					return left;
				}
				else if (node->_right != nullptr)
				{
					AVLNode *right = node->_right;
					delete node;
					return right;
				}
				else
				{
					return nullptr;
				}
			}
		}

		// �ڵݹ���ݹ����У����½ڵ�ĸ߶�ֵ
		node->_height = maxHeight(node->_left, node->_right) + 1;
		return node;
	}

	// ���ؽڵ�ĸ߶�
	int height(AVLNode *node)const
	{
		return node == nullptr ? 0 : node->_height;
	}

	// ���ؽ������������ߵĲ���
	int maxHeight(AVLNode *node1, AVLNode *node2)
	{
		return height(node1) > height(node2) ? height(node1) : height(node2);
	}

	// ����ת���� ��nodeΪ���ڵ��������ת��������ת��ĸ��ڵ�
	AVLNode* leftRotate(AVLNode* node)
	{
		AVLNode* child = node->_right;// �õ���ת��ĸ��ڵ�
		node->_right = child->_left;// �ø��ڵ��������������ԭ���ڵ��������
		child->_left = node;// �ø��ڵ��ԭ���ڵ��ɸýڵ��������
		node->_height = maxHeight(node->_left, node->_right) + 1; // ���½ڵ�߶�
		child->_height = maxHeight(child->_left, child->_right) + 1; // ���½ڵ�߶�
		return child; //������ת��ĸ��ڵ�
	}

	// ����ת����  ��nodeΪ���ڵ��������ת��������ת��ĸ��ڵ�
	AVLNode* rightRotate(AVLNode* node)
	{
		AVLNode* child = node->_left; // �õ��м�ڵ�
		node->_left = child->_right; //���м�ڵ��������������ԭ���ڵ��������
		child->_right = node;// ���м�ڵ��ԭ���ڵ��ɸýڵ�����ӽڵ�
		node->_height = maxHeight(node->_left, node->_right) + 1; // ���½ڵ�߶�
		child->_height = maxHeight(child->_left, child->_right) + 1;// ���½ڵ�߶�
		return child;//������ת��ĸ��ڵ�
	}

	//  ��-����ת
	AVLNode* leftBalance(AVLNode *node)
	{
		node->_left = leftRotate(node->_left);
		return rightRotate(node);
	}

	//  ��-����ת
	AVLNode* rightBalance(AVLNode *node)
	{
		node->_right = rightRotate(node->_right);
		return leftRotate(node);
	}

	//�ж�һ��  ������  �Ƿ���  ƽ�����������
	bool isAVLTree(AVLNode* node)
	{
	/*
	* �ж�һ��  ������  �Ƿ���  ƽ�����������  ������֮ǰ��д���ж�һ�Ŷ������Ƿ���
	* ����������(BST)�Ĵ��룬�����ڵݹ麯��ǰ���кܶ�������жϣ���ô����
	* ֻ��Ҫ���ⲿ�ּ�������������ж��Ƿ���ƽ�������ɡ��жϷ�ʽ��������
	* ��ͬ�ġ�
	*/
		static AVLNode* prev = nullptr;
		if (node == nullptr)
		{
			return true;
		}

		if (!isAVLTree(node->_left))
		{
			return false;
		}

		if (prev != nullptr && node->_data < prev->_data)
		{
			return false;
		}

		if (abs(level(node->_left) - level(node->_right)) > 1)
		{
			return false;
		}

		prev = node;
		return isAVLTree(node->_right);
	}

	//�ж�һ��  ����������  �Ƿ���  ƽ����
	bool isAVL(AVLNode *node)
	{
	/*
	* �ж�һ��  ����������  �Ƿ���  ƽ����  ����Ϊ��Ŀ�����Ѿ�˵���˸�����һ�ö���������
	* �ˣ��������ֱ�ӴӶ�����������ƽ������������������ϵ���Ҫ�������֣���һ��
	* ƽ�������������һ�������������߶Ȳ����1��������ǽ�����������ĺ���
	* level(),�ں����ݹ�ǰ�ж��Ƿ�������������ɣ��������㣬����ֱ�ӽ�����������
	* �����ݹ����������㼴�ɡ�
	*/
		if (node == nullptr)
		{
			return true;
		}

		if (abs(level(node->_left) - level(node->_right)) > 1)
		{
			return false;
		}
		return isAVL(node->_left) && isAVL(node->_right);
	}

	//���ĸ߶�
	int level(AVLNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		int left = level(node->_left);
		int right = level(node->_right);

		return (left > right ? left : right) + 1;
	}

	AVLNode *_root;
};

int main()
{
	AVL<int>avl;
	for (int i = 0; i < 10; ++i)
	{
		avl.insert(i);
	}
	cout << avl.isAVL() << endl;
	cout << avl.isAVLTree() << endl;
	cout << avl.level() << endl;
	avl.remove(8);
	return 0;
}

