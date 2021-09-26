//C++ program to print matrix in spiral fashion
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//......................................................

//function to print matrix in spiral fashion
void print(int lastR, int lastC, int ary[4][4])
{
    int startR, startC = 0;

    while (startR < lastR && startC < lastC)
    {
        //print the first row
        for (int  i = startC; i < lastC; i++)
        {
            cout<<ary[startR][i]<<' ';
        }
        //increment first row value
        startR++;


        //print the last column
        for (int i = startR; i < lastR; ++i)
        {
            cout<<ary[i][lastC]<<' ';
        }
        //decrease last column value
        lastC--;


        //print the last row
        if (startR < lastR)
        {
            for (int i = lastC - 1; i >= startC; --i)
            {
                cout<<ary[lastR - 1][i]<<' ';
            }
            lastR--;
        }


        //print the first column
        if ( startC < lastC )
        {
            for (int i = lastR - 1; i >= startR; --i)
            {
                cout<<ary[i][startC]<<' ';
            }
            startC++;
            
        }
        
    }
    
}

//.......................................................

int main()
{
    int array[4][4] = {{0, 1, 2, 3},
                       {4, 5, 6, 7},
                       {8, 9, 10, 11},
                       {12, 13, 14, 15}};

    //call the print function
    cout<<"this will print array in spiral fashion"<<'\n';
    cout<<"Array elements are:"<<'\n';
    cout<<"0, 1, 2, 3"<<'\n'
        <<"4, 5, 6, 7"<<'\n'
        <<"8, 9, 10, 11"<<'\n'
        <<"12, 13, 14, 15"<<'\n';

    print(4, 4, array);

    return 0;
}