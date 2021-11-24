//program to implement two stack using one array

#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Stack 
{
    private:
        int stk1, stk2;                                         //stk1 --> stack1  && stk2 --> stack2
        int size;                                               //size of array = stk1 + stk2;
        int* ary;

    public:
        Stack(int num)
        {                                                       //constructor fot initialization
            size = num;
            ary = new int[num];
            stk1 = -1;
            stk2 = size;
        }

        void push1(int num)                                     //method to push an element in stack 1 
        {
            if (stk1 < stk2 - 1)
            {
                stk1++;
                ary[stk1] = num;
                cout<<endl<<num<<" is pushed into Stack 1";
            }
            else
            {
                cout<<endl<<"Stack 1 overflowed.";
                return;
            }
        }

        void push2(int num)
        {                                                               //methos to push an element into Stack 2
            if (stk1 < stk2 - 1)
            {
                stk2--;
                ary[stk2] = num;
                cout<<endl<<num<<" is pushed into Stack 2";
            }
            else
            {
                cout<<endl<<"Stack 1 overflowed.";
                return;
            }
        }

        int pop1()                                                          //pop an element from stack 1
        {
            if (stk1 >= 0)
            {
                int x =  ary[stk1];
                stk1--;
                return x;
            }
            else
                cout<<endl<<"Stack Underflowed.";
                return 0;
        }

        int pop2()
        {                                                                   //pop an element from stack 2
            if (stk2 < size)
            {
                int x =  ary[stk2];
                stk2++;
                return x;
            }
            else
                cout<<endl<<"Stack Underflowed.";
                return 0;
        }

        ~Stack()
        {                                                                   //destructor
            delete[] ary;                                                   //free up space allocated using new
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack s(6);

    s.push1(6);                                                             //push elements into stk1 and stk2
    s.push2(9);
    s.push1(1);
    s.push2(2);
    s.push1(3);
    s.push2(7);

    cout<<endl<<s.pop1()<<" poped from Stack 1.";
    cout<<endl<<s.pop2()<<" poped from Stack 1.";
    
    return 0;
}