#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	_root = nullptr;
}

Node* BinaryTree::FindInsertionPoint(const int& value)
{
	Node* current = _root;

	while (true)
	{
		if (value >= current->_value)
		{
			if (current->_right == nullptr)
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

void BinaryTree::ChangeNodeInParent(Node* node, Node* changeNode)
{
	Node* parent = node->_parent;
	
	if (parent->_left->_value == node->_value)
	{
		parent->_left = changeNode;
	}
	else
	{
		parent->_right = changeNode;
	}
}

Node* BinaryTree::GetSmallestRightNode(Node* startNode)
{
	if (startNode->_right == nullptr)
	{
		return _root;
	}

	Node* current = startNode->_right;

	while (true)
	{
		if (current->_left == nullptr)
		{
			return current;
		}

		current = current->_left;
	}
}

BinaryTree& BinaryTree::AddElement(const int& value)
{
	Node* newNode = new Node(value);

	if (_root == nullptr)
	{
		_root = newNode;
	}
	else
	{
		Node* insertionPoint = FindInsertionPoint(value);
		newNode->_parent = insertionPoint;

		if (value >= insertionPoint->_value)
		{
			insertionPoint->_right = newNode;
		}
		else
		{
			insertionPoint->_left = newNode;
		}
	}

	return *this;
}

Node* BinaryTree::Search(const int& value)
{
	Node* current = _root;

	if (current->_value == value)
	{
		return _root;
	}

	while (true)
	{
		if (current->_value == value)
		{
			return current;
		}

		if (value >= current->_value)
		{

			if (current->_right == nullptr)
			{
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

bool BinaryTree::DeleteElement(const int& value)
{
	Node* deleteNode = Search(value);

	if (deleteNode == nullptr)
	{
		return false;
	}
	
	if (deleteNode->_left == nullptr && deleteNode->_right == nullptr)
	{
		ChangeNodeInParent(deleteNode, nullptr);
		delete deleteNode;
		return true;
	}
	//TODO: RSDN
	else if ((deleteNode->_left != nullptr && deleteNode->_right == nullptr) || (deleteNode->_left == nullptr && deleteNode->_right != nullptr))
	{
		if (deleteNode->_left != nullptr)
		{
			ChangeNodeInParent(deleteNode, deleteNode->_left);
		}
		else
		{
			ChangeNodeInParent(deleteNode, deleteNode->_right);
		}
		return true;
	}
	else
	{
		Node* smallestRightNode = GetSmallestRightNode(deleteNode);

		if (smallestRightNode->_right == nullptr)
		{
			deleteNode->_value = smallestRightNode->_value;
			ChangeNodeInParent(smallestRightNode, nullptr);
			delete smallestRightNode;
		}
		else
		{
			ChangeNodeInParent(smallestRightNode, smallestRightNode->_right);
			deleteNode->_value = smallestRightNode->_value;
			smallestRightNode->_right->_parent = smallestRightNode->_parent;
			delete smallestRightNode;
		}
		return true;
	}
}

//TODO: RSDN
void BinaryTree::PrintBinaryTree(Node* root, int space, int count) {
	if (root == nullptr) {
		return;
	}

	space += count;
	PrintBinaryTree(root->_right, space, count);

	cout << endl;

	//TODO: RSDN
	for (int i = count; i < space; i++) {
		cout << " ";
	}

	cout << root->_value << "\n";
	PrintBinaryTree(root->_left, space, count);
}

void BinaryTree::VisualisateBinaryTree()
{
	PrintBinaryTree(_root);
}

int BinaryTree::GetMax()
{
	if (_root == nullptr)
	{
		//TODO: nullptr
		return NULL;
	}

	Node* current = _root;

	while (current->_right != nullptr)
	{
		current = current->_right;
	}

	return current->_value;
}

int BinaryTree::GetMin()
{
	if (_root == nullptr)
	{
		//TODO: nullptr
		return NULL;
	}

	Node* current = _root;

	while (current->_left != nullptr)
	{
		current = current->_left;
	}

	return current->_value;
}

void BinaryTree::RemoveAll(Node* node)
{
	if (!node) return;

	RemoveAll(node->_left);
	RemoveAll(node->_right);

	delete node;
	node = nullptr;
}

BinaryTree::~BinaryTree()
{
	RemoveAll(_root);
}