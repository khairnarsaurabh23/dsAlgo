//C++ code to reverse th linked list in a groups of given size
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node 
{
    string str;
    Node* next;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Node* reverse(Node* head, int groupSize)
{
    Node* current = head;
    Node* previous = NULL;
    stack <Node*> groupStack;

    int count = 0;
    while (current != NULL)
    {
        while (groupSize > count)
        {
            groupStack.push(current);
            current = current->next;
            count++;
        }

        while (groupStack.size() > 0)
        {
            if (previous == NULL)
            {
                previous = groupStack.top();
                previous = head;
                groupStack.pop();
            } else {
                previous->next = groupStack.top();
                previous = previous->next;
                groupStack.pop();
            }
        }
    }
    previous->next = NULL;
    return head;
}
//........................................................

void addNode(Node* head, string str)
{
    Node* newNode = new Node;
    newNode->str = str;
    newNode->next = head;
    head = newNode;
}
//.......................................................

void display(Node* head)
{
    Node* current = head;
    cout<<endl;
    while (current != NULL)
    {
        cout<<" "<<current->str;
        current = current->next;
    }    
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node* head = NULL;

    addNode(head, "a");
    addNode(head, "b");
    addNode(head, "c");
    addNode(head, "d");
    addNode(head, "e");
    addNode(head, "f");
    addNode(head, "g");
    addNode(head, "h");
    addNode(head, "i");

    display(head);

    head = reverse(head, 3);

    display(head);

    return 0;

}