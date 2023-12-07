#include "TreapNode.h"

TreapNode::TreapNode()
{
	_x = 0;
	_y = 0;
	_left = nullptr;
	_right = nullptr;
}

TreapNode::TreapNode(const int& x, const int& y, TreapNode* left, TreapNode* right)
{
	_x = x;
	_y = y;
	_left = left;
	_right = right;
}