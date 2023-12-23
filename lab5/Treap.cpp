#include "Treap.h"
#include "TreapNode.h"

Treap::Treap()
{
	_root = nullptr;
}

TreapNode* Treap::Search(const int& key)
{
	TreapNode* current = _root;

	if (current->_x == key)
	{
		return _root;
	}

	while (true)
	{
		if (current->_x == key)
		{
			return current;
		}

		if (key >= current->_x)
		{

			if (current->_right == nullptr)
			{
				return nullptr;
			}
			else
			{
				current = current->_right;
			}

		}
		else
		{
			if (current->_left == nullptr)
			{
				return current;
			}
			else
			{
				current = current->_left;
			}
		}
	}
}

TreapNode* Treap::FindInsertionPoint(const int& key, const int& priority)
{
	if (_root == nullptr)
	{
		return nullptr;
	}

	TreapNode* current = _root;

	while (true)
	{
		if (key >= current->_x)
		{
			if (current->_right == nullptr)
			{
				return current;
			}
			else
			{
				if (priority > current->_y)
				{
					return current;
				}

				current = current->_right;
			}

		}
		else
		{
			if (current->_left == nullptr)
			{
				return current;
			}
			else
			{
				if (priority > current->_y)
				{
					return current;
				}

				current = current->_left;
			}
		}
	}
}

TreapNode* Treap::FindDeleteNode(const int& key)
{
	TreapNode* current = _root;

	while (true)
	{
		if (key >= current->_x)
		{
			if (current->_x == key)
			{
				return current;
			}
			else
			{
				if (current->_right != nullptr)
				{
					current = current->_right;
				}
				else
				{
					return nullptr;
				}

			}

		}
		else
		{
			if (current->_x == key)
			{
				return current;
			}
			else
			{
				if (current->_left != nullptr)
				{
					current = current->_left;
				}
				else
				{
					return nullptr;
				}
			}
		}
	}
}

TreapNode* Treap::Merge(TreapNode* firstTree, TreapNode* secondTree)
{
	if (secondTree == nullptr)
	{
		return firstTree;
	}

	if (firstTree == nullptr)
	{
		return secondTree;
	}

	if (firstTree->_y > secondTree->_y)
	{
		firstTree->_right = Merge(firstTree->_right, secondTree);
		return firstTree;
	}
	else
	{
		secondTree->_left = Merge(firstTree, secondTree->_left);
		return secondTree;
	}
}

pair<TreapNode*, TreapNode*> Treap::Split(TreapNode* tree, const int& key)
{
	if (tree == nullptr)
	{
		return make_pair(nullptr, nullptr);
	}
	
	if (key > tree->_x)
	{
		pair<TreapNode*, TreapNode*> trees = Split(tree->_right, key);
		tree->_right = trees.first;
		return make_pair(tree, trees.second);
	}
	else
	{
		pair<TreapNode*, TreapNode*> trees = Split(tree->_left, key);
		tree->_left = trees.second;
		return make_pair(trees.first, tree);
	}
}

Treap& Treap::AddNodeUnoptimized(const int& key, const int& priority)
{
	TreapNode* newNode = new TreapNode(key, priority);

	pair<TreapNode*, TreapNode*> trees = Split(_root, key);
	TreapNode* newTree = Merge(trees.first, newNode);
	_root = Merge(newTree, trees.second);
	
	return *this;
}

Treap& Treap::AddNodeOptimized(const int& key, const int& priority)
{
	_root = AddNodeOptimizedRecursion(_root, key, priority);
	return *this;
}

TreapNode* Treap::AddNodeOptimizedRecursion(TreapNode* root, const int& key, const int& priority)
{
	if (root == nullptr)
	{
		return new TreapNode(key, priority);
	}

	if (priority > root->_y)
	{
		pair<TreapNode*, TreapNode*> trees = Split(_root, key);
		TreapNode* newNode = new TreapNode(key, priority, trees.first, trees.second);
		return newNode;
	}
	else if (key < root->_x)
	{
		root->_left = AddNodeOptimizedRecursion(root->_left, key, priority);
	}
	else
	{
		root->_right = AddNodeOptimizedRecursion(root->_right, key, priority);
	}

	return root;
}

TreapNode* Treap::DeleteNodeUnoptimized(const int& key)
{
	TreapNode* deleteNode = FindDeleteNode(key);
	if (deleteNode)
	{
		pair<TreapNode*, TreapNode*> trees = Split(_root, key);
		pair<TreapNode*, TreapNode*> trees2 = Split(trees.second, key + 1);
		_root = Merge(trees.first, trees2.second);
		return _root;
	}

	return nullptr;
}

TreapNode* Treap::DeleteNodeOptimized(const int& key)
{
	TreapNode* deleteNode = FindDeleteNode(key);

	if (deleteNode)
	{
		if (deleteNode->_left == nullptr && deleteNode->_right == nullptr)
		{
			TreapNode* parent = FindInsertionPoint(deleteNode->_x + 1, deleteNode->_y);
			if (parent->_left->_x == deleteNode->_x)
			{
				parent->_left = nullptr;
			}
			else
			{
				parent->_right = nullptr;
			}

			delete deleteNode;

			return _root;
		}

		TreapNode* merged = Merge(deleteNode->_right, deleteNode->_left);
		deleteNode->_left = merged->_left;
		deleteNode->_right = merged->_right;
		deleteNode->_x = merged->_x;
		deleteNode->_y = merged->_y;
	}

	return nullptr;
}

const TreapNode* Treap::GetRoot()
{
	return _root;
}

void Treap::RemoveAll(TreapNode* node)
{
	if (!node) return;

	RemoveAll(node->_left);
	RemoveAll(node->_right);

	delete node;
	node = nullptr;
}

Treap::~Treap()
{
	RemoveAll(_root);
}