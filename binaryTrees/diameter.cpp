//ref: https://www.geeksforgeeks.org/diameter-of-a-binary-tree/

//C++ program to measure diameter of binary tree
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {
    int data;                                                               //skeleton for Nodes in tree
    Node *left, *right;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int diameter( Node* root, int* height)
{
    int leftHeight = 0, rightHeight = 0;                                     //for counting height of left and right side of each node
  
    int leftdiameter = 0, rightdiameter = 0;                                //for counting diameter of left and right side
  
    if (root == NULL) {
        *height = 0;                                                        //if Node is null set height and diameter to 0
        return 0;
    }
  
    leftdiameter = diameter(root->left, &leftHeight);                       //rucursive calls to the diameter function to calculate diameter
    rightdiameter = diameter(root->right, &rightHeight);
  
    *height = max(leftHeight, rightHeight) + 1;                             //set height var
  
    return max(leftHeight + rightHeight + 1, max(leftdiameter, rightdiameter));
}

Node* addNode(int data)                                                 //function to add new Nodes to the tree
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->right = newNode->left = NULL;
    return newNode;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *root  = addNode(1);                                               //add nodes to tree
    root->left  = addNode(34);
    root->right = addNode(55);
    root->right->left   = addNode(4);
    root->right->right  = addNode(70);
    root->right->left->left   = addNode(43);
    root->right->left->right  = addNode(55);
    root->right->right->left  = addNode(61);
    root->right->right->right = addNode(34);

    int height = 0;

    cout<<endl<<"Diameter of the tree is: "<<diameter(root, &height);

    return 0;
}