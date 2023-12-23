#include "Node.h"
//TODO: ������ �� �� ��������� IO ������ ���� �������� �� ��
#include <iostream>

using std::ostream;
//TODO: RSDN - ��� ������������
class BinaryTree
{
private:
	Node* _root;

	Node* FindInsertionPoint(const int& value);
	//TODO: ������ �� �� ��������� IO ������ ���� �������� �� ��
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

	//TODO: ������ �� �� ��������� IO ������ ���� �������� �� ��
	void VisualisateBinaryTree();

};