//C++ program to perform CRUD on Linked List
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node                                     //Node of Linked List
{
    int data;                                   //data in the Node
    Node* next;                                 //link to the next Node
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class LinkedList 
{
    private:
        Node* first;                            //pointer to the Node

    public:
        LinkedList()                            //constructor
        {
            first = NULL;                       //set no link
        }
    //...........................................................
        Node*  find(int data)
        {
            Node* current = first;
            while (true)
            {
                if (current->data == data)      //check for Node having correct data
                    return current;

               current = current->next ;
            }
            return first;
        }
    //.............................................................
        void addNode(int num)
        {
            Node* newNode = new Node;           //create a new Node
            newNode->data = num;                //assign the data 
            newNode->next = first;              //set pointer to NULL/next Node
            first = newNode;                    //set first to point towards newNode
        }
    //...............................................................
        void getData()
        {
            Node* current = first;
            while(current != NULL)
            {
                cout<<current->data<<endl;
                current = current->next;
            }
        }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    LinkedList l;

    l.addNode(23);                                      //add items to the linked list
    l.addNode(24);
    l.addNode(05);
    l.addNode(04);
    l.addNode(45);

    l.getData();                                        //get all items in the linked list

    return 0;
}