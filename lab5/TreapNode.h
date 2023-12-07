#pragma once

class TreapNode
{
public:
	TreapNode* _left;
	TreapNode* _right;
	int _x;
	int _y;

	TreapNode();
	TreapNode(const int& x, const int& y, TreapNode* left = nullptr, TreapNode* right = nullptr);
};