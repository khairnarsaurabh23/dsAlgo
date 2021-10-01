//C++ program to check whether the string is palindrome or not
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;

//................................................................

void palindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;                 //length() starts counting from 1 not 0

    while (end > start)
    {
        if (str[start++] != str[end--])
        {
            cout<<"Given string is not Palindrom";
            exit(0);
        }
    }
    
    
    cout<<"Given string is Palindrome."<<endl;
    exit(0);
    
}

//......................................................................

int main()
{
    string str;

    cout<<"Enter a string : "<<endl;
    cin>>str;

    palindrome(str);

    return 0;
}