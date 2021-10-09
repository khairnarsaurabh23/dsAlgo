//C++ program to reverse the linked list
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node                                                                 //strcture to store nodes in linked list
{
    int data;
    Node* next;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class linkedList
{
    private:
        Node* first;                                                        //pointer to Node
    
    public:
        linkedList()                                                        //set first to NULL by default
        {
            first = NULL;
        }
                //..................................................
        void addNode(int data)
        {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = first;
            first = newNode;
            cout<<endl<<"New Node added with data "<<data;
        }
                //...................................................
        void reverse()
        {
            Node* current = first;
            Node *nextNode = NULL, *previousNode = NULL;

            while(current != NULL)
            {
                nextNode = current->next;                                       //points to next node
                current->next = previousNode;                                   //reverses the link list
                previousNode = current;                                         //points to previous node
                current = nextNode;                                             //points to node undergoing operation
            }
            first = previousNode;                                               //set first to points last node
            cout<<endl<<"Linked List reversed!";
        }
                //....................................
        void display()
        {
            Node* current = first;
            while (current != NULL)
            {
                cout<<endl<<current->data;
                current = current->next;
            }
            cout<<endl;
            
        }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    linkedList list0;                                                           //initiate linked list

    list0.addNode(2);
    list0.addNode(5);
    list0.addNode(45);
    list0.addNode(22);
    list0.addNode(20);

    cout<<endl<<"Linked list before reversing: ";
    list0.display();
    
    list0.reverse();

    cout<<endl<<"Linked List after reversing: ";
    list0.display();

    return 0;
}