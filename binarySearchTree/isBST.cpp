//c++ program to detect that given tree is BST or not?
//khairnar saurabh

#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {                                                                   //skeleton for Nodes in BST
    int data;
    Node *left, *right;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool iSBST(Node* root)                                                          //function to check BST or not?
{
    Node* current = root;

    if (current->left == NULL || current->right == NULL)                        //if only root node then true
        return true;

    if (current->left->data >= current->data)                                   //condition for being BST
        return false;
    if (current->right->data <= current->data)                                  //condition for being BST
        return false;
    
    bool rightWing = iSBST(current->right);                                     //call recursively in right wing
    bool leftWing = iSBST(current->left);                                       //call recursively in left wing

    return (leftWing && rightWing);                                             //if both follow rules then pass
}

Node* addNode(int data)                             
{                                                                               //function to add nodes in the tree
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