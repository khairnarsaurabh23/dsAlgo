//cpp programe to reverse an array
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;


//function to reverse an array by swapping.
void reverse(int ary[], int first, int last)
{
    while (first < last)
    {
        int tmp = ary[first];     //swapping the first 
        ary[first] = ary[last];   //and last element 
        ary[last] = tmp;          // of the array
        first++;                  //increment first element
        last--;                   //decrement last element
    }
}

// a fun to print the reversed array
void print(int ary[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<< ary[i]<<"  ";          //print the array
    }

    cout<<endl;
}

//main function
int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //getting the size of the array
    int size = sizeof(array) / sizeof(array[0]);

    //printing the actual array
    cout<<"Array before the being reversed."<<endl;
    print(array, size);

    //reversing the array
    reverse(array, 0, size-1);

    //printing the reversed array
    cout<<"Array after being reversed."<<endl;
    print(array, size);

    return 0;
}