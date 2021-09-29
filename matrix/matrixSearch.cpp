//C++ program to search given element in respective predefined matrix
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
#define R 4                                  //macro's for program
#define C 4
//..................................................................................................................................

//function to search
int search(int num, int mat[R][C])
{
    //traverse through the matrix
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            //element found
            if (mat[i][j] == num)
            {
                cout<<"Element found at ["<<i<<"] ["<<j<<"] "<<endl;
                //return success status
                return 1;
            }   
        } 
    }

    cout<<"Err. Element nor Found";
    //return failed status
    return 0;
}


//function to print matrix
void print(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; i++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

//...........................................................................................................................

int main()
{
    int num;
    char res;                                         //looping porpose
    int mat[R][C] = {{34, 43, 67, 98},
                    {66, 77, 33, 55},
                    {10, 3, 8, 9},
                    {345, 675, 654, 345}};

    cout<<"The matrix is: "<<endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    do
    {
        cout<<"Enter an element in Matrix :"<<endl;
        cin>>num;
    
        search(num, mat);
        
        cout<<"Want to search again?(y/n): ";
        cin>>res;
    }while(res=='y');
    
}