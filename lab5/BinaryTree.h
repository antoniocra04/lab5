#include "Node.h"
//TODO: убрать из СД операциии IO должны быть отдельно от СД
#include <iostream>

using std::ostream;
//TODO: RSDN - нет комментариев
class BinaryTree
{
private:
	Node* _root;

	Node* FindInsertionPoint(const int& value);
	//TODO: убрать из СД операциии IO должны быть отдельно от СД
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

	//TODO: убрать из СД операциии IO должны быть отдельно от СД
	void VisualisateBinaryTree();

};