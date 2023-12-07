#include "Node.h"
#include <iostream>

using std::ostream;

class BinaryTree
{
private:
	Node* _root;

	Node* FindInsertionPoint(const int& value);
	void PrintBinaryTree(Node* root, int space = 0, int count = 5);
	void ChangeNodeInParent(Node* node, Node* changeNode);
	Node* GetSmallestRightNode(Node* startNode);
	void RemoveAll(Node* node);

public:
	BinaryTree();
	~BinaryTree();

	BinaryTree& AddElement(const int& value);
	bool DeleteElement(const int& value);
	Node* Search(const int& value);
	int GetMax();
	int GetMin();

	void VisualisateBinaryTree();

};