//C++ program to find row with max 1's
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;

#define R 5
#define C 5
//int row;                            //number of the row with max number of 1's
//..................................................................................................................................

//function to find max 1's in row
void find(bool ary[R][C])
{
    //max number of 1's in row
    int num = 0 , max = 0;
    int row;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (ary[i][j]==1)
                num++;
        }
        if (max<num)
            max = num;
            row = i ;
    }
    cout<<"row with max number of 1's is "<<row<<endl;
    cout<<"Counted from 1.";
}

void print(bool ary[R][C])
{
    cout<<"The 2d Array/Matrix is :"<<endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout<<ary[i][j]<<" ";
        }
        cout<<'\n';
    }
}
//..................................................................................................................................

int main()
{
    bool array[R][C] = {{1, 0, 0, 1, 1},
                        {1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 0}};
    
    cout<<"Note: This program considered unsorted matrix"<<endl;
    
    print(array);
    find(array);

    return 0;
}