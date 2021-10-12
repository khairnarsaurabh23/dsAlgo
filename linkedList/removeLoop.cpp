//C++ program to detect and remove the loop 
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node 
{
    int data;
    int flag;
    Node* next;
    Node(){ flag = 0;};
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void detectNRemove(Node* head)
{
    Node* current = head;
    while (head->next != NULL)
    {
        if (current->next->flag == 1)
        {
            cout<<endl<<"Node causing loop is:"<<current->data;
            current->next = NULL;
            cout<<endl<<"Loop Removed.";
            break;
        }
        current->flag = 1;
        current = current->next;
    }
}

void addNode(Node **head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node* head = NULL;

    addNode(&head, 9);
    addNode(&head, 8);
    addNode(&head, 6);
    addNode(&head, 0);
    addNode(&head, 1);
    addNode(&head, 4);
    addNode(&head, 5);

    head->next->next->next->next->next->next->next = head;

    detectNRemove(head);
    return 0;
}