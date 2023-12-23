#include <iostream>
#include "BinaryTree.h"
#include "Treap.h"
using namespace std;

void PrintTreap(const TreapNode* root, int space, int count) {
    if (root == nullptr) {
        return;
    }

    space += count;
    PrintTreap(root->_right, space, count);

    cout << endl;

    for (int i = count; i < space; i++) {
        cout << " ";
    }

    cout << root->_x << "," << root->_y << "\n";
    PrintTreap(root->_left, space, count);
}

void PrintBinaryTree(const Node* root, int space, int count)
{
    if (root == nullptr)
    {
        return;
    }

    space += count;
    PrintBinaryTree(root->_right, space, count);

    cout << endl;

    for (int i = count; i < space; i++)
    {
        cout << " ";
    }

    cout << root->_value << "\n";
    PrintBinaryTree(root->_left, space, count);
}


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
    string menu = "Choose one of activity:\
                   \n1 - Add\n2 - Remove\n3 - Search\n4 - Search min value\
                   \n5 - Search max value\nq - Exit to main menu\nYour choice: ";
    int value;
    BinaryTree* binaryTree = new BinaryTree;
    char mode = '\0';
    string enterMessage = "Enter value for ";
    string noValueMessage = "No value in binary tree!\n";
    string noNodeMessage = "No nodes in binary tree!\n";
    while (mode != 'q')
    {
        PrintBinaryTree(binaryTree->GetRoot(), 0, 5);
        cout << menu;
        ValidInput(mode);
        system("cls");

        switch (mode) {
            case '1':
                cout << enterMessage << "adding: ";
                ValidInput(value);
                binaryTree->AddElement(value);
                break;
            case '2':
                cout << enterMessage << "deletion: ";
                ValidInput(value);
                if (binaryTree->DeleteElement(value))
                {
                    cout << "Deletion successful!\n";
                }
                else
                {
                    cout << noValueMessage;
                }
                break;
            case '3':
                cout << "Enter value for search: ";
                ValidInput(value);
                if (binaryTree->Search(value))
                {
                    cout << "Value " << value << " is contained in binary tree!\n";
                }
                else
                {
                    cout << noValueMessage;
                }
                break;
            case '4':
                if (binaryTree->GetMin() != nullptr)
                {
                    cout << "Value " << binaryTree->GetMin()->_value << " is minimum in binary tree!\n";
                }
                else
                {
                    cout << noNodeMessage;
                }
                break;
            case '5':
                if (binaryTree->GetMax() != nullptr)
                {
                    cout << "Value " << binaryTree->GetMax()->_value << " is maximum in binary tree!\n";
                }
                else
                {
                    cout << noNodeMessage;
                }
                break;
            default:
                break;
        }
    }
}

void ControllerTreap()
{
    string menu = "Choose one of activity:\
                   \n1 - Add (Unoptimized)\n2 - Add (Optimized)\n3 - Delete (Unoptimized)\
                   \n4 - Delete (Optimized)\n5 - Search\nq - Exit to main menu\nYour choice: ";
    int key;
    int priority;
    Treap* treap = new Treap;
    char mode = '\0';
    string enterXMessage = "Enter x value for ";
    string enterYMessage = "Enter y value for ";
    string noValueMessage = "No value in treap!\n";
    string noNodeMessage = "No nodes in treap!\n";
    string successDeleteMessage = "Deletion successful!\n";

    while (mode != 'q')
    {
        PrintTreap(treap->GetRoot(), 0, 5);
        cout << menu;
        ValidInput(mode);
        system("cls");
        switch (mode) {
            case '1':
                cout << enterXMessage << "adding: ";
                ValidInput(key);
                cout << enterYMessage << "adding: ";
                ValidInput(priority);
                treap->AddNodeUnoptimized(key, priority);
                break;
            case '2':
                cout << enterXMessage << "adding: ";
                ValidInput(key);
                cout << enterYMessage << "adding: ";
                ValidInput(priority);
                treap->AddNodeOptimized(key, priority);
                break;
            case '3':
                cout << enterXMessage << "deletion: ";
                ValidInput(key);
                if (treap->DeleteNodeUnoptimized(key) != nullptr)
                {
                    cout << successDeleteMessage;
                }
                else
                {
                    cout << noNodeMessage;
                }
                break;
            case '4':
                cout << enterXMessage << "deletion: ";
                ValidInput(key);
                if (treap->DeleteNodeOptimized(key) != nullptr)
                {
                    cout << successDeleteMessage;
                }
                else
                {
                    cout << noNodeMessage;
                }
                break;
            case '5':
                cout << enterXMessage << "search: ";
                ValidInput(key);
                if (treap->Search(key))
                {
                    cout << "Value " << key << " is contained in treap!\n";
                }
                else
                {
                    cout << noValueMessage;
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