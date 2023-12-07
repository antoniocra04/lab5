#pragma once

class Node
{
public:
	Node* _left;
	Node* _right;
	Node* _parent;
	int _value;

	Node();
	Node(const int& value, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr);
};