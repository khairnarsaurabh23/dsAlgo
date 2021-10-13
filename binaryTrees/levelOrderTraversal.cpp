//C++ program to breadth-first-algorithm
//program will get the data the way its inserted into binary tree
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {
    string str;
    Node *left, *right;
};
/////////////////////////////////////////////////////////////////////

void print(Node *root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node* first = q.front();
        cout<<first->str<<" ";
        q.pop();

        if (first->left != NULL)
            q.push(first->left);
        if (first->right != NULL)
            q.push(first->right);
    }
}

Node* addNode(string str)
{
    Node* newNode = new Node;
    newNode->str = str;
    newNode->right = newNode->left = NULL;
    return newNode;
}
//////////////////////////////////////////////////////////////////////

int main()
{
    Node* root = addNode("21st");
    root->left = addNode("century");
    root->right = addNode("belongs");
    root->left->left = addNode("to");
    root->right->left = addNode("India");

    cout<<endl<<"Breadth-first-algorithm: "<<endl;
    print(root);
    return 0;
}