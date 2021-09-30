//C++ code for finding max number of 1's in row wise sorted matrix
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;

#define R 5
#define C 5             
//...................................................................

//function to find the index of the first 1
//we'll search into given row of the respective 2d array
int find(bool ary[], int start, int end)
{
    //iterate only if array is not empty
    if (end >= start)
    {
        //middle index
        int mid = start + (end - start) / 2;

        if (mid == 0 || ary[mid-1] == 0 && ary[mid] == 1)
            return mid;
        
        //recursive call to find
        //search on right
        else if (ary[mid] == 0)
            return find(ary, (mid + 1), end);

        //recursive call to the find
        //search on the left
        else
            return find(ary, start, (mid - 1));
        
    }
    return 1;
}

//function find row with max 1's
int findRow(bool ary[R][C] )
{
    int row_index = 0, max = 0;

    //finding index of first 1 in the row
    int i, index;
    for (int i = 0; i < R; i++)
    {
        index = find(ary[i], 0, C-1);
        if ( C-index > max)
        {
            max = C - index;
            row_index = i;
        }
    }
    return row_index;
}

//function to print the array
void print(bool ary[R][C])
{
    cout<<"The bool array is :"<<endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; i++)
        {
            cout<<ary[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//..........................................................................

int main()
{
    bool array[R][C] = {{0, 0, 0, 1, 1},
                        {0, 1, 1, 1, 1},
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1},
                        {1, 1, 1, 1, 1}};

    print(array);

    cout<<"Row withmax number of 1's is"<<findRow(array);

    return 0;
}//C++ code for finding max number of 1's in row wise sorted matrix
//khairnar saurabh

#include <bits/stdc++.h>
using namespace std;

#define R 5
#define C 5             
//...................................................................

//function to find the index of the first 1
//we'll search into given row of the respective 2d array
int find(bool ary[], int start, int end)
{
    //iterate only if array is not empty
    if (end >= start)
    {
        //middle index
        int mid = start + (end - start) / 2;

        if ((mid == 0 || ary[mid-1] == 0) && ary[mid] == 1)
            return mid;
        
        //recursive call to find
        //search on right
        else if (ary[mid] == 0)
            return find(ary, (mid + 1), end);

        //recursive call to the find
        //search on the left
        else
            return find(ary, start, (mid - 1));
        
    }
    return -1;
}

//function find row with max 1's
int findRow(bool ary[R][C] )
{
    int row_index = 0, max = 0;

    //finding index of first 1 in the row
    int i, index;
    for (i = 0; i < R; i++)
    {
        index = find(ary[i], 0, C-1);
        if (index != -1 && C-index >= max)
        {
            max = C - index;
            row_index = i;
            cout<<"max"<<max<<endl;
            cout<<"row_index"<<row_index<<endl;
            
        }
    }
    return row_index;
}


//..........................................................................

int main()
{
    bool array[R][C] = {{0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1},
                        {0, 0, 0, 0, 1},
                        {1, 1, 1, 1, 1}};

    

    int i = findRow(array);
    cout<<"Row with max number of 1's : ";
    cout<<i; 

    return 0;
}