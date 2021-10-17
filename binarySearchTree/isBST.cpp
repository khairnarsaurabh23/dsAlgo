//c++ program to detect that given tree is BST or not?
//khairnar saurabh

#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {
    int data;
    Node *left, *right;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool iSBST(Node* root)
{
    Node* current = root;

    if (current->left == NULL || current->right == NULL)
        return true;

    if (current->left->data >= current->data)
        return false;
    if (current->right->data <= current->data)
        return false;
    
    bool rightWing = iSBST(current->right);
    bool leftWing = iSBST(current->left);

    return (leftWing && rightWing);
}

Node* addNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *root  = addNode(40);                                               //add nodes to tree
    root->left  = addNode(34);
    root->right = addNode(55);
    root->right->left   = addNode(45);
    root->right->right  = addNode(70);

    if (iSBST(root))
        cout<<endl<<"The Given tree is BST.";
    else
        cout<<endl<<"The given tree isn't BST.";
    return 0;
}