#include "Treap.h"
#include "TreapNode.h"
//TODO: убрать из СД операциии IO должны быть отдельно от СД
#include <iostream>

using namespace std;

Treap::Treap()
{
	_root = nullptr;
}

TreapNode* Treap::Search(const int& x)
{
	TreapNode* current = _root;

	if (current->_x == x)
	{
		return _root;
	}

	while (true)
	{
		if (current->_x == x)
		{
			return current;
		}

		if (x >= current->_x)
		{

			if (current->_right == nullptr)
			{
				//TODO: убрать из СД операциии IO должны быть отдельно от СД
				cout << "Element not found";
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

TreapNode* Treap::FindInsertionPoint(const int& x, const int& y)
{
	if (_root == nullptr)
	{
		return nullptr;
	}

	TreapNode* current = _root;

	while (true)
	{
		if (x >= current->_x)
		{
			if (current->_right == nullptr)
			{
				return current;
			}
			else
			{
				if (y > current->_y)
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
				if (y > current->_y)
				{
					return current;
				}

				current = current->_left;
			}
		}
	}
}

TreapNode* Treap::FindDeleteNode(const int& x)
{
	TreapNode* current = _root;

	while (true)
	{
		if (x >= current->_x)
		{
			if (current->_x == x)
			{
				return current;
			}
			else
			{
				current = current->_right;
			}

		}
		else
		{
			if (current->_x == x)
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

pair<TreapNode*, TreapNode*> Treap::Split(TreapNode* tree, const int& x)
{
	if (tree == nullptr)
	{
		return make_pair(nullptr, nullptr);
	}
	
	if (x > tree->_x)
	{
		pair<TreapNode*, TreapNode*> trees = Split(tree->_right, x);
		tree->_right = trees.first;
		return make_pair(tree, trees.second);
	}
	else
	{
		pair<TreapNode*, TreapNode*> trees = Split(tree->_left, x);
		tree->_left = trees.second;
		return make_pair(trees.first, tree);
	}
}

Treap& Treap::AddNodeUnoptimized(const int& x, const int& y)
{
	TreapNode* newNode = new TreapNode(x, y);

	pair<TreapNode*, TreapNode*> trees = Split(_root, x);
	TreapNode* newTree = Merge(trees.first, newNode);
	_root = Merge(newTree, trees.second);
	
	return *this;
}

Treap& Treap::AddNodeOptimized(const int& x, const int& y)
{
	_root = AddNodeOptimizedRecursion(_root, x, y);
	return *this;
}

TreapNode* Treap::AddNodeOptimizedRecursion(TreapNode* root, const int& x, const int& y)
{
	if (root == nullptr)
	{
		return new TreapNode(x, y);
	}

	if (y > root->_y)
	{
		pair<TreapNode*, TreapNode*> trees = Split(_root, x);
		TreapNode* newNode = new TreapNode(x,y, trees.first, trees.second);
		return newNode;
	}
	else if (x < root->_x)
	{
		root->_left = AddNodeOptimizedRecursion(root->_left, x, y);
	}
	else
	{
		root->_right = AddNodeOptimizedRecursion(root->_right, x, y);
	}

	return root;
}

Treap& Treap::DeleteNodeUnoptimized(const int& x)
{
	pair<TreapNode*, TreapNode*> trees = Split(_root, x);
	pair<TreapNode*, TreapNode*> trees2 = Split(trees.second, x+1);
	_root = Merge(trees.first, trees2.second);
	return *this;
}

Treap& Treap::DeleteNodeOptimized(const int& x)
{
	TreapNode* deleteNode = FindDeleteNode(x);

	if (deleteNode->_left == nullptr && deleteNode->_right == nullptr)
	{
		TreapNode* parent = FindInsertionPoint(deleteNode->_x+1, deleteNode->_y);
		if (parent->_left->_x == deleteNode->_x)
		{
			parent->_left = nullptr;
		}
		else
		{
			parent->_right = nullptr;
		}

		delete deleteNode;

		return *this;
	}

	TreapNode* merged = Merge(deleteNode->_right, deleteNode->_left);
	deleteNode->_left = merged->_left;
	deleteNode->_right = merged->_right;
	deleteNode->_x = merged->_x;
	deleteNode->_y = merged->_y;

	return *this;
}
//TODO: RSDN
void Treap::PrintTreap(TreapNode* root, int space, int count) {
	if (root == nullptr) {
		return;
	}

	space += count;
	PrintTreap(root->_right, space, count);

	cout << endl;

	for (int i = count; i < space; i++) {
		cout << " ";
	}

	cout << root->_x << "," << root->_y << "\n";
	PrintTreap(root->_left, space, count);
}

void Treap::VisualisateTreap()
{
	PrintTreap(_root);
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