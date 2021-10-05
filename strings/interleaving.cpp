//C++ program to check whether a string is valid interleaving of other two strings
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//.......................................................................................

bool isShufle(char s0[], char s1[], char s2[])
{
    int len0, len1, len2;

    //get the length of strings
    len0 = strlen(s0);
    len1 = strlen(s1);
    len2 = strlen(s2);

    //if legth dosen't matches , return false
    if(len2 != len0 + len1)
        return false;

    //loop until the end of the string
    while(*s2)
    {
        //check for char in s0
        if(*s0==*s2)
        {
            s0++;
            break;
        }

        //check for char in s1
        else if (*s1==*s2)
        {
            *s1++;
            break;
        }

        //else string isn't interleaving
        else 
            return false;

        //if char found increment char in s2
        *s2++;
        
    }
    return true;
}

//..........................................................................................

int main()
{
    char s0[] = "PQR";
    char s1[] = "STU";
    char s2[] = "USTQPR";

    if(isShufle(s0,s1,s2))
        cout<<"The string s2 is interleaving of s1, s0";
    else
        cout<<"The string s2 isn't interleaving of s1, s0";

    return 0;
}