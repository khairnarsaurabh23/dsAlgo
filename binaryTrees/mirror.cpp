//ref: https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

// C++ program to convert a Binary tree to its mirror
//khairnar saurabh

#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node                                                     //skeleton for tree Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mirror(Node* root)                                                     //function to mirror the tree
{
	if (root == NULL)                                                       //if NULL exit
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* current = q.front();                                             //current points to the front of the queue
		q.pop();                                                                //pop the pointer from the queue

        //---IMPORTANT-----
        //this is the only thing different from
        //levelOederTraversal.cpp
		Node* temp = NULL;                                                        
        temp= current->left;                                                       //swap the Node pointers, so the is tree mirrored
        current->left = current->right;
        current->right = temp; 

		if (current->left)
			q.push(current->left);                                             //push pointers to the Nodes in queue
		if (current->right)
			q.push(current->right);
	}
}

Node* addNode(int data)                                                         //add Node to the tree
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

void print(Node* node)                                                              //print the tree
{
	if (node == NULL)
		return;
	print(node->left);
	cout << node->data << " ";
	print(node->right);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	cout << endl<<" Inorder traversal of tree: "<<endl;
	print(root);

	mirror(root);

	cout << endl<<"Inorder traversal after mirror: "<<endl;
	print(root);

	return 0;
}
