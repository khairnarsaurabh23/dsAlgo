//cpp program for implementation of the stack from scrach


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
////////////////////////////////////////////////////////////////////

class Stack 
{
    private:
        int num;    //number of elements in stack
    
    public:
        int ary[MAX];
        Stack() {num = -1;}
        bool push(int x)
        {
            if (num >= (MAX - 1))
            {
                cout<<endl<<"Stack Overflow";
                return false;
            }
            else
            {
                ary[++num] = x;
                cout<<endl<<" "<<x<<" pushed in stack at "<<num;
                return true;
            }
        }

        int pop()
        {
            if (num < 0 )
            {
                cout<<endl<<"Stack Underflow";
                return false;
            }
            else
            {
                int x = ary[num];
                for (int i = num; i < 1; i--)
                    ary[i] = ary[i+1];
                num--;
                cout<<endl<<"Element at the top is poped.";
                return x;
            }
        }

        int top()
        {
            if (num < 0 )
            {
                cout<<endl<<"Empty stack";
                return 0;
            }
            else
            {
                int x = ary[num];
                return x;
            }
            
        }
        bool isEmpty()
        {
            return (num < 0);
        }
};

///////////////////////////////////////////////////

int main() 
{
    class Stack s;
    s.push(23);
    s.push(24);
    s.push(50);

    s.pop();

    cout<<endl<<"Element at top is:"<<s.top();

    return 0;
}