// Queue using arrays
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
    return (q->rear == q->size - 1);
}
void display(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = q->front; i <= q->rear; i++)
        cout << q->arr[i] << " ";
    cout << endl;
}
void enqueue(queue *&q, int val)
{
    if (isFull(q))
    {
        cout << "Queue full! " << val << " cannot be inserted." << endl;
        return;
    }
    if (isEmpty(q))
        q->front++;
    q->arr[++q->rear] = val;
}
int dequeue(queue *&q)
{
    if (isEmpty(q))
    {
        cout << "Queue empty! Cannot dequeue element." << endl;
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}
void buildQueue(queue *&q)
{
    int data;
    cout << "Enter value of node to be inserted: ";
    cin >> data;
    while (data != -1)
    {
        enqueue(q, data);
        cout << "Enter value of node to be inserted: ";
        cin >> data;
    }
}

// Queue using linked lists
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is now free for node with data = " << value << endl;
    }
};
Node *front = NULL;
Node *rear = NULL;
bool isEmpty(Node *front, Node *rear)
{
    return (front == NULL && rear == NULL);
}
void enqueue(Node *&front, Node *&rear, int val)
{
    Node *nodeToBeInserted = new Node(val);
    if (isEmpty(front, rear))
        front = rear = nodeToBeInserted;
    else
    {
        rear->next = nodeToBeInserted;
        rear = nodeToBeInserted;
    }
}
void dequeue(Node *&front, Node *&rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue empty! Cannot dequeue element." << endl;
        return;
    }
    Node *temp = front;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    temp->next = NULL;
    delete temp;
}

// While in a queue, elements are inserted to the rear and deleted from the front, in a DE queue, both operations can be performed at either of the sides. Hence, DE queue does not follow FIFO / LILO
// /*
// 1. Input-restricted DE queue: Insertion to the front not permitted
// 2. Output-restricted DE queue: Deletion from the rear not permitted
// */
// #include <stdio.h>
// #include <stdlib.h>
// struct queue
// {
//     int size; // size of array
//     int f, r;
//     int *arr;
// };
// int isFull(struct queue *q)
// {
//     if (q->r == q->size - 1)
//         return 1;
//     else
//         return 0;
// }
// void en queueRear(struct queue *q, int val)
// {
//     if (isFull(q))
//         cout << " queue full! " << val << " cannot be inserted";
//     else
//     {
//         q->r++;
//         q->arr[q->r] = val;
//     }
// }
// void en queueFront(struct queue *q, int val)
// {
//     if (isFull(q) && q->f == -1)
//         cout << " queue full! " << val << " cannot be inserted";
//     else
//     {
//         q->arr[q->f] = val;
//         q->f--;
//     }
// }
// void de queueFront(struct queue *q)
// {
//     int a = -1;
//     if (q->f == q->r) // condition for  queue to be empty
//         cout << " queue empty! de queueFront() operation cannot be performed";
//     else
//     {
//         q->f++;
//         a = q->arr[q->f];
//     }
//     return a;
// }
// void de queueRear(struct queue *q)
// {
//     int a = -1;
//     if (q->f == q->r) // condition for  queue to be empty
//         cout << " queue empty! de queueRear() operation cannot be performed";
//     else
//     {
//         a = q->arr[q->r];
//         q->r--;
//     }
//     return a;
// }
// int main()
// {
//     struct queue q;
//     q.size = 10;
//     q.f = q.r = -1;
//     q.arr = (int *)malloc(q.size * sizeof(int));
//     en queueRear(&q, 12);
//     de queueFront(&q);
//     return 0;
// }