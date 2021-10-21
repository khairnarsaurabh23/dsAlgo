//C++ program to find predecessor and successor of Node with given data
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {
    int data;
    Node *left , *right;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search(Node* root, Node* &predecessor, Node* &successor, int data)
{
    if (root == NULL)
        return;

    if (root->data == data)                                                                 //if node with given data is found
    {
        if (root->left != NULL)                                                             //predecessor is right most Node on lrft side
        {
            Node* current = root->left;
            while (current->right)
                current = current->right;
            predecessor = current;                                                          //predesessor will hold pointer to the Node with data just less
        }                                                                                   //than given data

        if (root->right != NULL)
        {
            Node* current = root->right;                                                    //successor id the left most node on right side
            while (current->left)                                                           //successor is will hold pointer to node with data just greater than given
                current = current->left;
            successor = current;
        }
        return;
    }

    if (data > root->data)                                                                      //if data is greater search in right side
    {
        successor = root;
        search(root->right, predecessor, successor, data);
    } else {                                                                                    //else search in right side
        predecessor = root;
        search(root->left, predecessor, successor, data);
    }
}

Node* addNode(int data)                                                                         //function to add nodes in BST
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *root = addNode(50);                                                        //add new Nodes to the tree
    root->left = addNode(30);
    root->right = addNode(70);
    root->left->left = addNode(20);
    root->left->right = addNode(40);
    root->right->left = addNode(60);
    root->right->right = addNode(80);

    cout<<endl<<"The BST is: ";
    inorder(root);                                                                  //get the inorder traversal of the BST

    Node* predecessor = NULL, *successor = NULL;
    search(root, predecessor, successor, 65);                                       //call to search function

    if (predecessor != NULL)
        cout<<endl<<"predecessor: "<<predecessor->data;
    else
        cout<<endl<<"predecessor: NULL";

    if (successor != NULL )
        cout<<endl<<"successor: "<<successor->data;
    else
        cout<<endl<<"successor: NULL";  

    return 0;
}