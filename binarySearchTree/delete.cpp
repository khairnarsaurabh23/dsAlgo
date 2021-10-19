//ref: https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

//C++ program to delte an element from  BST
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {                                                                   //skeleton for Node in tree
    int data;
    Node *left, *right;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Node* deleteNode(Node* root, int data)                                                                //function to delete a Node
{
    if (root == NULL)                                                                       //best case:0
    return root;

    if (root->data > data) {                                                                //if required node is in leftwing
        root->left = deleteNode(root->left, data);
        return root;
    }
    else if (root->data < data) {                                                           //if required node is in rightwing
        root->right = deleteNode(root->right, data);
        return root;
    }

    if (root->left == NULL)                                                                 //case1:if left child is absent
    {
        Node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL)                                                         //case2:if right child is absent
    {
        Node* temp = root->left;
        delete root;
        return temp;
    }else                                                                                   //case3:if both childs are present
    {
        Node* parent = root;
        Node* successor = parent->right;
        while (successor != NULL)
        {
            parent = successor;
            successor = successor->left;
        }

        if (parent == root)
            parent->right = successor->right;
        else
            parent->left = successor->right;

        root->data = successor->data;
        delete successor;
        return root;
    }    
}

Node* addNode(int data)                                                             //function to add new Nodes to the tree
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
    Node *root = addNode(4);                                                        //add new Nodes to the tree
    root->left = addNode(2);
    root->right = addNode(5);
    root->left->left = addNode(1);
    root->left->right = addNode(3);

    cout<<endl<<"Inorder traversal of tree is: ";
    inorder(root);
    
    root = deleteNode(root, 5);

    cout<<endl<<"Inorder traversal of tree is: ";
    inorder(root);

    return 0;
}