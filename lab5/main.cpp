#include <iostream>
#include "BinaryTree.h"
#include "Treap.h"
using namespace std;

template <typename T>
void ValidInput(T& variable)
{
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter correct value: ";
        cin >> variable;
    }
}

void ControllerBinaryTree()
{
    //TODO: RSDN
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\n4 - Search min value\n5 - Search max value\nq - Exit to main menu\nYour choice: ";
    int value;
    //TODO: выделение пам€ти через new
    BinaryTree binaryTree;
    char mode = '\0';

    while (mode != 'q')
    {
        binaryTree.VisualisateBinaryTree();
        cout << menu;
        ValidInput(mode);
        system("cls");
        //TODO: RSDN
        switch (mode) {
        case '1':
            cout << "Enter value for adding: ";
            ValidInput(value);
            binaryTree.AddElement(value);
            break;
        case '2':
            cout << "Enter value for deletion: ";
            ValidInput(value);
            if (binaryTree.DeleteElement(value))
            {
                cout << "Deletion successful!\n";
            }
            //TODO: DRY - don't repeat yourself
            else
            {
                cout << "No value " << value << " in binary tree!\n";
            }
            break;
        case '3':
            cout << "Enter value for search: ";
            ValidInput(value);
            if (binaryTree.Search(value))
            {
                cout << "Value " << value << " is contained in binary tree!\n";
            }
            //TODO: DRY - don't repeat yourself
            else
            {
                cout << "No value " << value << " in binary tree!\n";
            }
            break;
        case '4':
            //TODO: nullptr
            if (binaryTree.GetMin() != NULL)
            {
                cout << "Value " << binaryTree.GetMin() << " is minimum in binary tree!\n";
            }
            //TODO: DRY - don't repeat yourself
            else
            {
                cout << "No nodes in binary tree!\n";
            }
            break;
        case '5':
            //TODO: nullptr
            if (binaryTree.GetMax() != NULL)
            {
                cout << "Value " << binaryTree.GetMax() << " is maximum in binary tree!\n";
            }
            //TODO: DRY - don't repeat yourself
            else
            {
                cout << "No nodes in binary tree!\n";
            }
            break;
        default:
            break;
        }
    }
}

void ControllerTreap()
{
    //TODO: RSDN
    string menu = "Choose one of activity:\n1 - Add (Unoptimized)\n2 - Add (Optimized)\n3 - Delete (Unoptimized)\n4 - Delete (Optimized)\n5 - Search\nq - Exit to main menu\nYour choice: ";
    //TODO: переменна€ должна объ€вл€тьс€ как можно ближе к инициализации RSDN
    //TODO: RSDN naming
    int x;
    int y;
    //TODO: выделение пам€ти через new
    Treap treap;
    char mode = '\0';

    while (mode != 'q')
    {
        treap.VisualisateTreap();
        cout << menu;
        ValidInput(mode);
        system("cls");
        //TODO: RSDN
        switch (mode) {
        case '1':
            cout << "Enter x for adding: ";
            ValidInput(x);
            cout << "Enter y for adding: ";
            ValidInput(y);
            treap.AddNodeUnoptimized(x, y);
            break;
        case '2':
            cout << "Enter x for adding: ";
            ValidInput(x);
            cout << "Enter y for adding: ";
            ValidInput(y);
            treap.AddNodeOptimized(x, y);
            break;
        case '3':
            cout << "Enter x for deletion: ";
            ValidInput(x);
            treap.DeleteNodeUnoptimized(x);
            break;
        case '4':
            cout << "Enter x for deletion: ";
            ValidInput(x);
            treap.DeleteNodeOptimized(x);
            break;
        case '5':
            cout << "Enter x for search: ";
            ValidInput(x);
            if (treap.Search(x))
            {
                cout << "Value " << x << " is contained in treap!\n";
            }
            else
            {
                cout << "No value " << x << " in treap!\n";
            }
            break;
        default:
            break;
        }
    }
}

void MainController()
{
    string menu = "Choose one of structure:\n1 - Binary tree\n2 - Treap\nq - Quit\nYour choice: ";
    char mode = '\0';

    while (mode != 'q')
    {
        cout << menu;
        ValidInput(mode);
        system("cls");
        switch (mode) {
        case '1':
            ControllerBinaryTree();
            break;
        case '2':
            ControllerTreap();
            break;
        default:
            break;
        }
    }
}

int main()
{
    MainController();

    return 0;
}