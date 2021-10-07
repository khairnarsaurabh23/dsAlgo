//C++ program for searching element in the rotated sorted array
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;
//.........................................................................................

int binary(int ary[], int start, int end, int value)
{
    int mid = start + (end - start)/2;

    if (ary[mid] == value)
        return mid;
   
    //search on RHS of mid
    else if (ary[mid] < value)
        return binary(ary, mid+1, end, value);

    //else search on RHS of mid
    return binary(ary, start, mid-1, value);
    
}

int findPivote(int ary[], int start, int end)
{
    if (end == start)
        return start;

    int mid = start + (end - start)/2;

    //check pivote in the middle
    if (mid < end && ary[mid] > ary[mid+1])
        return mid;
    if (mid > start && ary[mid-1] > ary[mid])
        return (mid - 1);

    //if not found
    //search on the LHS
    if (ary[start] >= ary[mid])
        return findPivote(ary, start, mid-1);

    //else search on the RHS
    return findPivote(ary, mid+1, end);
}


int  binarySearch(int ary[], int end, int value)
{
    //starting position of the array
    int start = 0;

    //find the pivote in the array
    int pivote = findPivote(ary, start, end-1);

    if (ary[pivote] == value)
        return pivote;

    //binary search for value on the LHS of pivote
    if (ary[0] <= value)
        return binary(ary, start, pivote-1, value);
    
    //binary search for value on the RHS of pivote
    return binary(ary, pivote+1, end, value);

    
}

//.........................................................................................

int main()
{
    int array[] = {12, 14, 23, 45,50, 51,  3, 6, 8, 9, 11};

    int num = sizeof(array)/sizeof(array[0]);
    int value = 14;

    int index = binarySearch(array, num, value);
    
    cout<<"Index of the element is: "<<index;

    return 0;
}