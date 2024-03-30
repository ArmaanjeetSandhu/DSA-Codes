/*
While in a queue, elements are inserted to the rear and deleted from the front, in a deque (double-ended queue), both operations can be performed at either of the ends. Hence, deques do not obey the FIFO (first-in-first-out) principle.
1. Input-restricted deque: Insertion can be made at one end only
2. Output-restricted deque: Deletion can be made at one end only
*/
// Deque using arrays
#include <iostream>
using namespace std;
class deque
{
public:
    int *arr;
    int size;
    int front, rear;
    deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
};
bool isEmpty(deque *q)
{
    return (q->front == -1 && q->rear == -1);
}
bool isFull(deque *q)
{
    return ((q->front == 0 && q->rear == q->size - 1) || (q->rear == (q->front - 1) % (q->size - 1)));
}
void pushBack(deque *&q, int value)
{
    if (isFull(q))
    {
        cout << "Queue full! " << value << " cannot be inserted." << endl;
        return;
    }
    if (isEmpty(q))
    {
        q->front++;
        q->rear++;
    }
    else if (q->rear == q->size - 1 && q->front != 0)
        q->rear = 0;
    else
        q->rear++;
    q->arr[q->rear] = value;
}
int popFront(deque *&q)
{
    if (isEmpty(q))
    {
        cout << "Queue empty!" << endl;
        return -1;
    }
    int ans = q->arr[q->front];
    q->arr[q->front] = -1;
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else if (q->front == q->size - 1)
        q->front = 0;
    else
        q->front++;
    return ans;
}
void pushFront(deque *&q, int value)
{
    if (isFull(q))
    {
        cout << "Queue full! " << value << " cannot be inserted." << endl;
        return;
    }
    if (isEmpty(q))
    {
        q->front++;
        q->arr[++q->rear] = value;
        return;
    }
    if (q->front == 0)
    {
        int temp = q->arr[q->front];
        q->front = q->size - 1;
        q->arr[q->front] = temp;
        q->arr[0] = value;
    }
}
int popBack(deque *&q)
{
    if (isEmpty(q))
    {
        cout << "Queue empty! Cannot dequeue element." << endl;
        return -1;
    }
}