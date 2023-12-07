#include "Node.h"

Node::Node()
{
	_value = 0;
	_left = nullptr;
	_right = nullptr;
	_parent = nullptr;
}

Node::Node(const int& value, Node* left, Node* right, Node* parent)
{
	_value = value;
	_left = left;
	_right = right;
	_parent = parent;
}