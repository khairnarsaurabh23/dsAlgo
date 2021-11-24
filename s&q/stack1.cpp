//program to implement two stack using one array

#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Stack 
{
    private:
        int stk1, stk2;
        int size;
        int* ary;

    public:
        Stack(int num)
        {
            size = num;
            ary = new int[num];
            stk1 = -1;
            stk2 = size;
        }

        void push1(int num)
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
        {
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

        int pop1()
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
        {
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
        {
            delete[] ary;
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack s(6);

    s.push1(6);
    s.push2(9);
    s.push1(1);
    s.push2(2);
    s.push1(3);
    s.push2(7);

    cout<<endl<<s.pop1()<<" poped from Stack 1.";
    cout<<endl<<s.pop2()<<" poped from Stack 1.";

    //cout<<endl<<"error at: "<<*(0x4961EEB);

    return 0;
}