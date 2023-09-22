#include <iostream>
using namespace std;
class queue
{
public:
    int *arr;
    int size;
    int front, rear;
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
};
bool isEmpty(queue *q)
{
    return (q->front == -1 && q->rear == -1);
}
bool isFull(queue *q)
{
    return ((q->front == 0 && q->rear == q->size - 1) || (q->rear == (q->front - 1) % (q->size - 1)));
}
void enqueue(queue *&q, int val)
{
    if (isFull(q))
    {
        cout << "Queue full! " << val << " cannot be inserted." << endl;
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
    q->arr[q->rear] = val;
}
int dequeue(queue *&q)
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