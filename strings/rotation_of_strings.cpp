//C++ program to find whether the given strings 
//are rotation of each other

//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//..................................................................

//function to check if strings are rotation or not
bool rotation(string str1, string str2)
{
    if(str1.length() != str2.length())  //if length not equal, not rotation
    {
        cout<<"Strings are not rataion of each other.";
        return false;   
    }

    //concate the string str1 with itself
    string temp = str1 + str1;


    if(temp.find(str2))             //strings  are rotation of each other
    {
        cout<<"Strings are rotation of each other";
        return true;
    }                       
}

//.......................................................................

int main()
{
    string s1, s2;

    //check for valid input
    while(true) 
    {
        cout<<"\nEnter first string: ";
        cin >> s1;
        if(cin.good())                  //check if input is good
        {
            cin.ignore(50, '\n');       //extract and discard upto 50 or '\n'
            break;
        }
        else
        {
            cout<<"\nBad Input, Try Again !";
            continue;
        }
    
    }
    
    
    //check for valid input for s2
    while(true) 
    {
        cout<<"\nEnter second string: ";
        cin >> s2;
        if(cin.good())                  //check if input is good
        {
            cin.ignore(50, '\n');       //extract and discard upto 50 or '\n'
            break;
        }
        else
        {
            cout<<"\nBad Input, Try Again !";
            continue;
        }
    }

    rotation(s1, s2);

    return 0;
}