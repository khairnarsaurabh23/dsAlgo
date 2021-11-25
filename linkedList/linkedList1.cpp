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
            first = NULL;                       //points to nothing
        }
    //...........................................................
        Node*  find(int data)                                           //returns pointer to the node previous to required node
        {
            Node* current = first;
            if (first->data == data)                                    //if required Node id first 
                return first;
                
            while (true)
            {
                if ((current->next)->data == data)                              //check for Node having correct data
                    return current;

               current = current->next ;
            }
            //return first;
        }
    //..............................................................
        void deleteNode(int data)
        {
            //Node* del = find(data);                                     //find the node with respective data
            Node* previous = find(data);                                    //pointer to point at previous Node of del
            if (previous == first)                                        //want to delete last node
            {
                first = previous->next;                                      //node first will point to second last node
                delete previous;
                previous = NULL;
                cout<<"\nDelete Node having data "<<data<<endl;
                return;
            }
            
            // while (previous->next != del)                               //check for node from second last node
            //     previous = previous->next;

            previous->next = (previous->next)->next;
            (previous->next)->next = NULL;
            cout<<"\nDelete Node having data "<<data;
            
        }
    //.............................................................
        void insertNode(int index, int data)
        {
            Node* newNode = new Node;                                   //Node going to be added in Linked List
            Node* current = first;                                      //pointer to first Node of the Linked List
            
            int i =1;
            while (i != index-1)                                        //loop until Node previous to desired Node
            {
                current = current->next; 
                i++;
            }                             
            
            newNode->data = data;                                       //add newNode
            newNode->next = current->next;
            current->next = newNode;
            cout<<endl<<"New Node inserted at:"<<index<<" with data "<<data;
        }
    //.............................................................
        void updateNode(int data, int updateData)                       //function to update data in respective Node
        {
            Node* updateNode = find(data);
            (updateNode->next)->data = updateData;                            //find returns  previous Node of required one
            cout<<endl<<"Updated node having data "<<data<<" with "<<updateData;
        }
    //.............................................................
        void addNode(int data)
        {
            Node* newNode = new Node;                                   //create a new Node
            newNode->data = data;                                        //assign the data 
            newNode->next = first;                                      //set pointer to NULL/next Node
            first = newNode;                                            //set first to point towards newNode
            cout<<endl<<"New Node added at the first position. Data:"<<data;
        }
    //...............................................................
        void getData()                                                  //display all nodes
        {
            Node* current = first;
            while(current != NULL)
            {
                cout<<endl<<current->data;
                current = current->next;
            }
            cout<<endl;
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

    l.getData();
    l.deleteNode(45);
    l.insertNode(3, 17);
    l.updateNode(17, 1);
    l.getData();

    return 0;
}