//c++ program for finding min and mix in  the array
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;

//...........................................................................................

//function to find the maximum number in the array
int maximum(int ary[], int size)
{
    int max = ary[0];

    for ( int i = 0; i < size; i++)
    {
        if(ary[i]>max)                                          //compare to get maximum number/check for max
            max = ary[i];                                       //assign maximum no to the max var
            continue;                                           //continue with next iteration 
    }
    return max;
}


//function to find the minimum no in the array
int minimum(int ary[], int size)
{
    int min = ary[0];

    for (int  i = 0; i < size; i++)
    {
        if (ary[i]<min)                                         //check for min
        {
            min = ary[i];                                       //assign to the min
            continue;                                           //continue with next iteration
        }
    }
    return min;
}


//function to print array
void print(int ary[], int size)
{
    cout<<"The array is:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<ary[i]<<" ";
    }
    cout<<endl;
}

//..................................................................................................

int main()
{
    int array[] = {23, 45, 54, 32, 56, 78, 99, 123, 345, 567, 76, 3};

    int size = sizeof(array) / sizeof(array[0]);                            //get the size of the array

    print(array, size);

    int min = minimum(array, size);
    int max = maximum(array, size);

    cout<<endl<<max<<" is the maximum number in the respective array."<<endl;
    cout<<endl<<min<<" is the minimun number in the respective array."<<endl;

    return 0;
}
