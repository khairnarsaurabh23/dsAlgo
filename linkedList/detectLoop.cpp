//C++ program to detect the loop in linked list
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////

struct Node                                                             //Node to hold linked list
{
    int data;
    Node* next;
};
/////////////////////////////////////////////////////////////////////////////////

void addNode(Node** head, int data)                                     //function to add a node
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode; 
}

bool detectLoop(Node *head)                                               //function to detect a loop
{                                                                         //return true if loop is found, else false
    Node *first = head, *second = head->next;
    while (first != NULL && second != NULL && second->next != NULL)
    {
        if (first == second)
            return true;
        first = first->next;
        second = first->next->next;
    }
    return false;
}

//alternative solution
// {                                                                       
//     unordered_set<Node*> s;                                          //store pointers to linked list in random fashion                                            
//     while (head != NULL)
//     {
//         if (s.find(head) != s.end())
//             return true;
        
//         s.insert(head);
//         head = head->next;
//     }
//    return false;
}
//////////////////////////////////////////////////////////////////////

int main()
{
    Node* head = NULL;

    addNode(&head, 20);                                                 //adding nodes 
    addNode(&head, 2);
    addNode(&head, 23);
    addNode(&head, 0);
    addNode(&head, 56);
    addNode(&head, 54);
    addNode(&head, 1);
    addNode(&head, 10);

    head->next->next->next->next->next->next->next->next = head;          //create a loop

    if (detectLoop(head))
        cout<<"Loop Found";
    else
        cout<<"No Loop";

    return 0;
}
