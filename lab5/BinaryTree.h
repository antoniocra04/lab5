#include "Node.h"

class BinaryTree
{
private:
	Node* _root;

	/// <summary>
	/// Поиск узла для вставки
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>Node*</returns>
	Node* FindInsertionPoint(const int& value);

	/// <summary>
	/// Изменить ссылку родителя элемента на другой элемент
	/// </summary>
	/// <param name="node">узел</param>
	/// <param name="changeNode">узел на который нужно заменить</param>
	void ChangeNodeInParent(Node* node, Node* changeNode);

	/// <summary>
	/// Найти самый малый правый элемент
	/// </summary>
	/// <param name="startNode">начальный узел</param>
	/// <returns>Node*</returns>
	Node* GetSmallestRightNode(Node* startNode);

	/// <summary>
	/// Удаление всех элементов дерева
	/// </summary>
	/// <param name="node">узел</param>
	void RemoveAll(Node* node);

public:
	BinaryTree();
	~BinaryTree();

	/// <summary>
	/// Добавить узел
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>BinaryTree&</returns>
	BinaryTree& AddElement(const int& value);

	/// <summary>
	/// Удаление узла
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>0 или 1 в зависимости от успешности удаления</returns>
	bool DeleteElement(const int& value);

	/// <summary>
	/// Поиск узла
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>Node*</returns>
	Node* Search(const int& value);

	/// <summary>
	/// Поиск узла с максимальным значением
	/// </summary>
	/// <returns>узел</returns>
	Node* GetMax();

	/// <summary>
	/// Поиск узла с минимальным значением
	/// </summary>
	/// <returns>узел</returns>
	Node* GetMin();

	/// <summary>
	/// Получить корень дерева
	/// </summary>
	/// <returns>Node*</returns>
	const Node* GetRoot();
};