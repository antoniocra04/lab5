#pragma once
#include <utility>
#include "TreapNode.h"
using namespace std;
//TODO: RSDN - нет комментариев
class Treap
{
private:
	TreapNode* _root;

	TreapNode* Merge(TreapNode* firstTree, TreapNode* secondTree);
	//TODO: RSDN - naming, не понятно, что такое x и y
	pair<TreapNode*, TreapNode*> Split(TreapNode* tree, const int& x);
	//TODO: убрать из СД операциии IO должны быть отдельно от СД
	void PrintTreap(TreapNode* root, int space = 0, int count = 5);
	TreapNode* FindInsertionPoint(const int& x, const int& y);
	TreapNode* FindDeleteNode(const int& x);
	TreapNode* AddNodeOptimizedRecursion(TreapNode* root, const int& x, const int& y);
	void RemoveAll(TreapNode* node);

public:
	Treap();
	~Treap();

	TreapNode* Search(const int& x);
	Treap& AddNodeUnoptimized(const int& x, const int& y);
	Treap& AddNodeOptimized(const int& x, const int& y);
	Treap& DeleteNodeUnoptimized(const int& x);
	Treap& DeleteNodeOptimized(const int& x);
	//TODO: убрать из СД операциии IO должны быть отдельно от СД
	void VisualisateTreap();
};