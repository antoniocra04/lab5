#pragma once
#include <utility>
#include "TreapNode.h"
using namespace std;

class Treap
{
private:
	TreapNode* _root;

	/// <summary>
	/// Слияние деревьев
	/// </summary>
	/// <param name="firstTree">Первое дерево</param>
	/// <param name="secondTree">Второе Дерево</param>
	/// <returns>TreapNode*</returns>
	TreapNode* Merge(TreapNode* firstTree, TreapNode* secondTree);
	
	/// <summary>
	/// Разрезание дерева
	/// </summary>
	/// <param name="tree">Дерево</param>
	/// <param name="key">ключ по которому будет происходить разрез</param>
	/// <returns>Пара деревьев которые получились при разрезании</returns>
	pair<TreapNode*, TreapNode*> Split(TreapNode* tree, const int& key);

	/// <summary>
	/// Найти узел для вставки
	/// </summary>
	/// <param name="key">ключ</param>
	/// <param name="priority">приоритет</param>
	/// <returns>TreapNode*</returns>
	TreapNode* FindInsertionPoint(const int& key, const int& priority);

	/// <summary>
	/// Поиск удаляемого узла
	/// </summary>
	/// <param name="root">корень дерева</param>
	/// <param name="key">ключ</param>
	/// <param name="priority">приоритет</param>
	/// <returns>TreapNode*</returns>
	TreapNode* FindDeleteNode(const int& key);

	/// <summary>
	/// Рекурсивная функция для оптимизированного добавления элемента
	/// </summary>
	/// <param name="root">корень дерева</param>
	/// <param name="key">ключ</param>
	/// <param name="priority">приоритет</param>
	/// <returns>TreapNode*</returns>
	TreapNode* AddNodeOptimizedRecursion(TreapNode* root, const int& key, const int& priority);

	/// <summary>
	/// Удаление всех элементов
	/// </summary>
	/// <param name="root">корень дерева</param>
	void RemoveAll(TreapNode* node);

public:
	Treap();
	~Treap();
	
	/// <summary>
	/// Поиск узла
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>TreapNode*</returns>
	TreapNode* Search(const int& key);

	/// <summary>
	/// Добавить узел неоптимизированным методом
	/// </summary>
	/// <param name="key">ключ</param>
	/// <param name="priority">ключ</param>
	/// <returns>Treap&</returns>
	Treap& AddNodeUnoptimized(const int& key, const int& priority);

	/// <summary>
	/// Добавить узел оптимизированным методом
	/// </summary>
	/// <param name="key">ключ</param>
	/// <param name="priority">ключ</param>
	/// <returns>Treap&</returns>
	Treap& AddNodeOptimized(const int& key, const int& priority);

	/// <summary>
	/// Удалить узел неоптимизированным методом
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>Treap&</returns>
	TreapNode* DeleteNodeUnoptimized(const int& key);

	/// <summary>
	/// Удалить узел оптимизированным методом
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>Treap&</returns>
	TreapNode* DeleteNodeOptimized(const int& key);

	/// <summary>
	/// Получить корень дерева
	/// </summary>
	/// <returns>TreapNode*</returns>
	const TreapNode* GetRoot();
};