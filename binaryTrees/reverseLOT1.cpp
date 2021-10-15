//C++ program to print REVERSE level order traversal 
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node
{
	int data;
	Node* left;
    Node* right;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reverseLevelOrder(Node* root)
{
	stack <Node *> s;
	queue <Node *> q;
	q.push(root);


	while (q.empty() == false)
	{
		root = q.front();
		q.pop();
		s.push(root);

		if (root->right)
			q.push(root->right);

		if (root->left)
			q.push(root->left);
	}


	while (s.empty() == false)
	{
		root = s.top();
		cout << root->data << " ";
		s.pop();
	}
}


Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	struct Node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;
}
