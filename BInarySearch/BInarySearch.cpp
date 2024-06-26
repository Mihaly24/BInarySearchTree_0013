#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    // Constructor for the node class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    Node* ROOT;

    BinaryTree() {
        ROOT = nullptr; // initializing root to null
    }

    void insert(string element)
    {
        Node* newNode = new Node(element, nullptr, nullptr); // allocate memory for new node
        newNode->info = element; //assign value to data field
        newNode->leftchild = nullptr; // make left null
        newNode->rightchild = nullptr; // make right null

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); // locate the parent

        if (parent == nullptr)
        {
            ROOT = newNode;
            return; //exit
        }
        if (element < parent->info) //if the data is less than the parent
        {
            parent->leftchild = newNode; // make the left point to new node
        }
        else if (element > parent->info)
        {
            parent->rightchild = newNode;
        }
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        // This Function searches the currentNode of the specified Node as well as the current Node of its per
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree obj;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            obj.insert(word);
            break;
        }
        case '2':
        {
            obj.inorder(obj.ROOT);
            break;
        }
        case '3':
        {
            obj.preorder(obj.ROOT);
        }
        case '4':
        {
            obj.postorder(obj.ROOT);
        }
        case '5':

            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}