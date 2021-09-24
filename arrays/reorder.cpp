//C++ program to move negetive elements to the right of the array
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//........................................................

//function to print array
void print(int ary[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", ary[i]);       //cheekh cheekh ke bata de sabko !
    
    printf("\n");
}


//divide and conquire
void divide(int ary[], int size)
{
    int num, j;
    for (int i = 1; i < size; i++)
    {
        num = ary[i];                       //pakdo, chodna mat!

        if (num >= 0)                        //(+num) chhod do isse!
            continue;

        j = i - 1;
        while (j >= 0 && ary[j] >= 0 ){      //-num ko apni jagah pe bhejenge!
            ary[j + 1] = ary[j];            //move, move quick!
            j = j - 1;
        }
        ary[j + 1] = num;                   //set ho gaya -num.
    }
    
}

//.....................................................................

int main()
{
    int array[] = {-2, -4, 5, 3, 6, -5, -45, 6, 0, -56, 44};

    //count the elements
    int size = sizeof(array)/sizeof(array[0]);

    cout<<"Peoples before 'Divide and Conquire':"<<'\n';
    print(array, size);

    divide(array, size);

    cout<<"Peoples After 'Divide and Conquire':"<<'\n';
    print(array, size);
}