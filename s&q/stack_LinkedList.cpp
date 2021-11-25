//basic stack implementation using linked list

#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {
    int data;
    Node* next;
};

class Stack 
{
    private:
        Node* root;

    public:
        Stack()
        {
            root = NULL;
        }

        void push(int data)
        {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = root;
            root = newNode;
            cout<<endl<<" "<<data<<" pushed into Stack";
        }

        void pop()
        {
            Node* temp = root;
            root = root->next;
            cout<<endl<<temp->data<<" is poped";
            free(temp);
        }

        int  front()
        {
            return root->data;
        }

        int rear()
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
    Stack s;

    s.push(66);
    s.push(45);
    s.push(83);
    s.push(89);

    s.pop();

    cout<<endl<<"Front: "<<s.front();
    cout<<endl<<"Last: "<<s.rear();

    return 0;
}