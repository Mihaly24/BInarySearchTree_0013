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

       
    }
};

int main()
{
    
}