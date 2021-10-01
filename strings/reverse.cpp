//C++  program to reverse the given string
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;

//...........................................

void reverse(string str)
{
    for (int  i = str.length()-1; i>=0; i--)
    {
        cout<<str[i];
    }
}

//............................................

int main()
{
    string str;
    cout<<"Enter a string (end with '\n'):"<<endl;
    cin>>str;

    reverse(str);

    return 0;
}