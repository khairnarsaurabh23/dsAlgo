//C++ program to find duplicate chats in string
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//................................................................

//function to find and print the duplicated chars
void find(char str[])
{
    cout<<'\n';
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        //if null, skip 
        if(str[i] == ' ')
            continue;

        for (int j = i+1; j < strlen(str); j++)
        {
            //check for duplicate chars in the string
            if (str[i] == str[j] )
            {
                //increment count if duplicate found
                count++;
                str[j] = ' ';
                continue;
            }
        }

        if(count!=0)
        {
            cout<<"Character: "<<str[i]<<"       "<<"Repeated: "<<count<<endl;
            count = 0;
        }
    }
}

//..........................................................................

int main()
{
    char string[] = "This is cpp program to find duplicate strings\n";
    for(int i=0; i<strlen(string); i++)
        cout<<string[i];

    find(string);

    return 0;

}