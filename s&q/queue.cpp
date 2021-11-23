//program to implement basic Queue using array
//https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Queue {                                                       //queue class
    public:
        int first, last, size, capacity;
        int* ary;
};


Queue* createQueue(int num)                                         //function to create a queue
{
    Queue* q = new Queue();
    q->capacity = num;                                              //capacity of the queue
    q->first = q->size = 0;                                         //initializing queue with zero elements
    q->last = num - 1;                                              //element is dequeued from last and enqueued from front
    q->ary = new int[num];                                          //array holding queue elements
    return q;
}

int isFull(Queue* q )
{                                                                   //function to check queue id overflowed or not
    return (q->size == q->capacity);
}

int isEmpty(Queue* q)
{                                                                   //function to check queue is underflowed or not
    return (q->size == 0);
}

void enqueue(Queue* q, int item)
{                                                                   //function to enqueue an element into queue from front
    if(isFull(q))
    {
        cout<<endl<<"Queue is full/Overflowed.";
        return;
    }
    q->last = (q->last + 1) % q->capacity;
    q->ary[q->last] = item;
    q->size = q->size + 1;
    cout<<endl<<item<<" is enqueued to Queue.";
}

int dequeue(Queue* q)
{                                                                       //function to dequeue an element from queue
    if(isFull(q))
    {
        cout<<endl<<"Queue is full/Overflowed.";
        return 0;
    }
    int item = q->ary[q->first];
    q->first = (q->first + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

int front(Queue* q)
{
    if (isEmpty(q))                                                     //function to get first element of the queue
    {
        cout<<endl<<"Queue is empty/Underflowed.";
        return 0;
    }
    return q->ary[q->first];
}

int rear(Queue* q)
{                                                                   //function to get last element of queue
    if (isEmpty(q))
    {
        cout<<endl<<"Queue is empty/Underflowed.";
        return 0;
    }
    return q->ary[q->last];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Queue* q = createQueue(10);

    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 55);
    enqueue(q, 44);

    cout<<endl<<dequeue(q)<<" dequeued from Queue";

    cout<<endl<<"Front: "<<front(q);
    cout<<endl<<"Last: "<<rear(q);

    return 0;
}
