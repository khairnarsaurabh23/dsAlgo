//basic stack implementation using linked list

#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {                                               //Nodes of linked list
    int data;
    Node* next;
};

class Stack                                                 //class to initiate and perform other operations on Linked List & Stack
{
    private:
        Node* root;

    public:
        Stack()
        {
            root = NULL;
        }

        void push(int data)                                 //push data into stack
        {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = root;
            root = newNode;
            cout<<endl<<" "<<data<<" pushed into Stack";
        }

        void pop()                                              //function to pop an element from Stack
        {
            Node* temp = root;
            root = root->next;
            cout<<endl<<temp->data<<" is poped";
            free(temp);
        }

        int  front()                                            //getter function : get data at Top of Stack
        {
            return root->data;
        }

        int rear()                                              //getter function: get data at bottom of Stack
        {
            Node* current = root;
            while (current->next)
                current = current->next;
            return current->data;
            
        }

        ~Stack()                                                    
        {
            delete root;
        }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack s;                                                    //initiate Linked list 

    s.push(66);                                                 //push elements into linked list
    s.push(45);
    s.push(83);
    s.push(89);

    s.pop();                                                    //pop an element from Stack

    cout<<endl<<"Front: "<<s.front();
    cout<<endl<<"Last: "<<s.rear();

    return 0;
}