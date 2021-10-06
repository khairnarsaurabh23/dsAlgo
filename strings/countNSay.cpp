//C++ program to for count and say problem
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//..............................................................................

string countNSay(string str)
{
    string final = "";

    //to iterate over str
    int i = 0;
    while (i < str.length())
    {
        //store the number times digit repeated
        int count = 1;

        //is the string is enough long 
        //and holds same num in second position 
        while ((i + 1 < str.length()) && str[i] == str[i+1])
        {
            i++;
            count++;
        }


        //stream class to operate on strings
        stringstream tmp; 
        tmp << count;           //insert count to stringstream

        
        //extract string input from stringstream
        string strcount = tmp.str();
        final += (strcount + str[i]);
        i++; 
    }

    return final;
}

//..............................................................................

int main()
{
    int num;
    cout<<"\nInput a number: ";
    cin>>num;
    
    string str = "1";

    for (int i = 0; i != num; i++)
    {
        
         str = countNSay(str);
        //show the required result
        if(i + 1  == num)
            cout<<"\nThe result is: "<<str; 
    }
    return 0;
}