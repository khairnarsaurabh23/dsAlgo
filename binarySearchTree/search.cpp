//C++ program to search an element in BST
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {
    int data;
    Node *left, *right;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Node* search(Node* root, int data)
{
    Node* current = root;

    if (current->data == data)
        return current;
    
    if (current->data > data)
    {
        if (current->left == NULL)
            return NULL;
        else 
            current->left = search(current->left, data);
    }
    
    if (current->data < data)
    {
        if (current->right == NULL)
            return NULL;
        else
            current->right = search(current->right, data);
    }
}

Node* addNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *root = addNode(4);
    root->left = addNode(2);
    root->right = addNode(5);
    root->left->left = addNode(1);
    root->left->right = addNode(3);

    

    if (search(root, 1) == NULL)
        cout<<endl<<"Node not found.";
    else
        cout<<endl<<"Node found ";

    return 0;
}