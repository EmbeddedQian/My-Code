#include"stdafx.h"

#if 0

enum Color
{
	BLACK,
	RED
};

template<typename T>
class RBTree
{
public:
	RBTree() :_root(nullptr) {}

	// ������Ĳ���
	void insert(const T &val)
	{
		if (_root == nullptr)
		{
			_root = new RBNode(val, BLACK);
			return;
		}

		RBNode *parent = nullptr;
		RBNode *cur = _root;
		while (cur != nullptr)
		{
			parent = cur;
			if (cur->_data > val)
			{
				cur = cur->_left;
			}
			else if (cur->_data < val)
			{
				cur = cur->_right;
			}
			else
			{
				return;
			}
		}

		RBNode *node = new RBNode(val, RED, parent);
		if (val < parent->_data)
		{
			parent->_left = node;
		}
		else
		{
			parent->_right = node;
		}

		if (color(parent) == RED)
		{
			fixAfterInsert(node);
		}
	}

	//�������ɾ������
	void remove(const T &val)
	{
		if (_root == nullptr)
			return;

		RBNode *parent = nullptr;
		RBNode *cur = _root;
		while (cur != nullptr)
		{
			if (cur->_data > val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_data < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				break;
			}
		}

		if (cur == nullptr)
			return;

		if (cur->_left != nullptr && cur->_right != nullptr)
		{
			RBNode *old = cur;
			parent = cur;
			cur = cur->_left;
			while (cur->_right != nullptr)
				cur = cur->_right;
			old->_data = cur->_data;
		}

		RBNode *child = cur->_left;
		if (child == nullptr)
			child = cur->_right;

		if (child != nullptr)
		{
			child->_parent = cur->_parent;
			if (cur->_parent == nullptr)
			{
				_root = child;
			}
			else
			{
				if (cur->_parent->_left == cur)
				{
					cur->_parent->_left = child;
				}
				else
				{
					cur->_parent->_right = child;
				}
			}

			Color color = color(cur);
			delete cur;

			if (color == BLACK)
			{
				fixAfterRemove(child);
			}
		}
		else
		{
			if (parent == nullptr)
			{
				_root = nullptr;
			}
			else
			{
				if (color(cur) == BLACK)
				{
					fixAfterRemove(cur);
				}

				if (cur->_parent->_left == cur)
				{
					cur->_parent->_left = nullptr;
				}
				else
				{
					cur->_parent->_right = nullptr;
				}
				delete cur;
			}
		}
	}

	
	
	//while (node->_parent != nullptr)
			//{
			//	if (node->_parent->_left == node)
			//	{
			//		//1
			//		if (node->_parent->_right->_color == RED)
			//		{
			//			setColor(node->_parent, RED);
			//			setColor(node->_parent->_right, BLACK);
			//			leftRotate(node->_parent);
			//		}
			//		//2
			//		if (node->_parent->_right->_color == BLACK)
			//		{
			//			setColor(node->_parent->_right, RED);
			//			node = node->_parent;
			//		}
			//		//3
			//		if (node->_parent->_right->_color == BLACK&&node->_parent->_right->_left->_color == RED);
			//		{ 
			//			setColor(node->_parent->_right->_left, BLACK);
			//			setColor(node->_parent->_right, RED);
			//			rightRotate(node->_parent->_right);
			//		}
			//		//4
			//		if (node->_parent->_right->_color == BLACK&&node->_parent->_right->_right->_color == BLACK)
			//		{
			//			set(node->_parent->right, Color(node->_parent));
			//			set(node->_parent, BLACK);
			//			leftRotate(node->_parent);
			//		}
			//		//5
			//		if (node->_color == RED)
			//		{
			//			if(node->_parent->_color==RED)
			//		}
			//	}
			//}

private:
	//����ڵ�
	struct RBNode
	{
		RBNode(T data = T(),
			Color color = BLACK,
			RBNode *parent = nullptr)
			:_data(data)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(parent)
			, _color(color)
		{}
		T _data;
		RBNode *_left;
		RBNode *_right;
		RBNode *_parent;
		Color _color;
	};

	//������Ĳ������
	void fixAfterInsert(RBNode *node)
	{
		while (color(parent(node)) == RED)
		{
			if (left(parent(parent(node))) == parent(node))
			{
				// ���������Ƚڵ������������
				RBNode *uncle = right(parent(parent(node)));
				// ���1
				if (color(uncle) == RED)
				{
					setColor(parent(node), BLACK);
					setColor(uncle, BLACK);
					setColor(parent(parent(node)), RED);
					node = parent(parent(node));
				}
				else
				{
					// ���3
					if (node == right(parent(node)))
					{
						node = parent(node);
						leftRotate(node);
					}

					// ���2
					setColor(parent(node), BLACK);
					setColor(parent(parent(node)), RED);
					rightRotate(parent(parent(node)));
					break;
				}
			}
			else
			{
				// ���������Ƚڵ������������
				RBNode *uncle = left(parent(parent(node)));
				// ���1
				if (color(uncle) == RED)
				{
					setColor(parent(node), BLACK);
					setColor(uncle, BLACK);
					setColor(parent(parent(node)), RED);
					node = parent(parent(node));
				}
				else
				{
					// ���3
					if (node == left(parent(node)))
					{
						node = parent(node);
						rightRotate(node);
					}

					// ���2
					setColor(parent(node), BLACK);
					setColor(parent(parent(node)), RED);
					leftRotate(parent(parent(node)));
					break;
				}
			}
		}

		setColor(_root, BLACK);
	}

	//�������ɾ������
	void fixAfterRomove(RBNode*node)
	{
		while (Color(node) == BLACK)
		{
			if (left(parent(node)) == node)
			{
				RBNode *brother = right(parent(node));
				if (color(brother) == RED)
				{
					setColor(brother, BLACK);
					setColor(parent(node), RED);
					leftRotate(parent(node));
					brother = right(parent(node));
				}

				if (color(left(brother)) == BLACK
					&& color(right(brother) == BLACK)
				{
					setColor(brother, RED);
					node = parent(node);
				}
				else
				{
					if (color(right(brother)) != RED)
					{
						setColor(brother, RED);
						setColor(left(brother), BLACK);
						rightRotate(brother);
						brother = right(parent(node));
					}

					setColor(brother, color(parent(node)));
					setColor(parent(node), BLACK);
					leftRotate(parent(node));
				}
			}
			else
			{
				RBNode *brother = left(parent(node));
				if (color(brother) == RED)
				{
					setColor(brother, BLACK);
					setColor(parent(node), RED);
					rightRotate(parent(node));
					brother = left(parent(node));
				}

				if (color(left(brother)) == BLACK
					&& color(right(brother) == BLACK)
				{
					setColor(brother, RED);
					node = parent(node);
				}
				else
				{
					if (color(left(brother)) != RED)
					{
						setColor(brother, RED);
						setColor(right(brother), BLACK);
						leftRotate(brother);
						brother = left(parent(node));
					}

					setColor(brother, color(parent(node)));
					setColor(parent(node), BLACK);
					rightRotate(parent(node));
				}
			}

		}
	}	

	//��ȡ�����ɫ
	Color color(RBNode *node)
	{
		return node == nullptr ? BLACK : node->_color;
	}

	//���ýڵ���ɫ
	void setColor(RBNode *node, Color color)
	{
		node->_color = color;
	}

	//��ȡ�ڵ�����ӽ��
	RBNode* left(RBNode *node)
	{
		return node->_left;
	}

	// ��ȡ�ڵ���Һ��ӽ��
	RBNode* right(RBNode *node)
	{
		return node->_right;
	}

	// ��ȡ�ڵ�ĸ��׽��
	RBNode* parent(RBNode *node)
	{
		return node->_parent;
	}

	//����ת
	void leftRotate(RBNode *node)
	{
		RBNode* child = node->_right;

		node->_right = child->_left;
		child->_left = node;
	}

	//����ת
	void rightRotate(RBNode *node)
	{
		RBNode* child = node->_left;

		node->_left = child->_right;
		child->_right = node;
	}

	RBNode *_root; // ָ�������ĸ��ڵ�
};

#endif
