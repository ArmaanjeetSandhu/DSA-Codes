// Queue using arrays
#include <iostream>
#include <vector>
using namespace std;
class queue
{
public:
    int size;
    int front, rear;
    vector<int> arr;
    queue(int size) : size(size), front(0), rear(-1), arr(size) {}
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front --> ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " --- ";
        cout << "<-- Rear" << endl;
    }
    bool isFull()
    {
        return rear == size - 1;
    }
    bool isEmpty()
    {
        return rear < front;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue full! " << val << " cannot be inserted." << endl;
            return;
        }
        arr[++rear] = val;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int dequeuedValue = arr[front++];
        if (isEmpty()) // reset indices if the queue becomes empty
        {
            front = 0;
            rear = -1;
        }
        return dequeuedValue;
    }
    int frontOfQueue()
    {
        return (isEmpty()) ? -1 : arr[front];
    }
};

// Queue using linked lists
#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;
void linkedListTraversal(struct node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void en queue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        printf(" queue is Full");
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
            f = r = n;
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
        printf(" queue is Empty\n");
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
// While in a  queue, elements are inserted to the rear and deleted from the front, in a DE queue, both operations can be performed at either of the sides. Hence, DE queue does not follow FIFO / LILO
/*
1. Input-restricted DE queue: Insertion to the front not permitted
2. Output-restricted DE queue: Deletion from the rear not permitted
*/
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size; // size of array
    int f, r;
    int *arr;
};
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    else
        return 0;
}
void en queueRear(struct queue *q, int val)
{
    if (isFull(q))
        cout << " queue full! " << val << " cannot be inserted";
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
void en queueFront(struct queue *q, int val)
{
    if (isFull(q) && q->f == -1)
        cout << " queue full! " << val << " cannot be inserted";
    else
    {
        q->arr[q->f] = val;
        q->f--;
    }
}
void de queueFront(struct queue *q)
{
    int a = -1;
    if (q->f == q->r) // condition for  queue to be empty
        cout << " queue empty! de queueFront() operation cannot be performed";
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
void de queueRear(struct queue *q)
{
    int a = -1;
    if (q->f == q->r) // condition for  queue to be empty
        cout << " queue empty! de queueRear() operation cannot be performed";
    else
    {
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    en queueRear(&q, 12);
    de queueFront(&q);
    return 0;
}