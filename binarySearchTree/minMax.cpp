//C++ program to find min and max in BST
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {                                                                   //skeleton for each node in BST
    int data;
    Node *left, *right;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Node* addNode(int data);                                                            //addNode declaration

Node* insert(Node* root, int data)                                                  //function to search a Node in BST
{
    Node* current = root;

    if (current == NULL)
        return addNode(data);
    
    if (current->data > data)                                                  
        current->left = insert(current->left, data);                                //add a Node if it doesn't exist
    
    if (current->data < data)
        current->right = insert(current->right, data);                               //add a Node if it doesn't exist
}

Node* minNumber(Node* root)                                                         //function to return pointer to Node
{                                                                                   //with minimum value
    Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
    
}

Node* maxNumber(Node* root)                                                         //function to return pointer to node
{                                                                                   //with max value
    Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

Node* addNode(int data)                                                             //function to add a node in BST
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(Node* root)                                                            //inorder traversal function
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *root = addNode(4);
    root->left = addNode(2);
    root->right = addNode(5);
    root->left->left = addNode(1);
    root->left->right = addNode(3);
 
    cout<<"Binary Search Tree: ";
    inorder(root);                                                                  //print BST
    insert(root, 7);                                                                //insert a Node into BST
    cout<<endl<<"Binary Search Tree: ";
    inorder(root);                                                                  //print BST
    
    cout << "\n Minimum value in BST is " << minNumber(root)->data;
    cout << "\n Maximum value in BST is " << maxNumber(root)->data;

    return 0;
}