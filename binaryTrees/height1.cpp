// C++ program to find height of tree
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node                                                                     //node of trees
{
	int data;
	Node* left;
	Node* right;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int height(Node* root)                                                      //function to measure height recursively
{
	if (root == NULL)
		return 0;
	else
	{
		int leftHeight = height(root->left);                                 //recursive calls
		int rightHeight = height(root->right);
	
		/* use the larger one */
		if (leftHeight > rightHeight)                                        //count the height after the function call completed
			return(leftHeight + 1);
		else return(rightHeight + 1);
	}
}

Node* addNode(int data)                                                     //function create new nodes
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	
	return(newNode);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Driver code
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
	
	cout << "Height of tree is " << height(root);
	return 0;
}