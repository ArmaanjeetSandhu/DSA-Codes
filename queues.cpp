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
void enqueue(queue *&q, int value)
{
    if (isFull(q))
    {
        cout << "Queue full! " << value << " cannot be inserted." << endl;
        return;
    }
    if (isEmpty(q))
        q->front++;
    q->arr[++q->rear] = value;
}
int dequeue(queue *&q)
{
    if (isEmpty(q))
    {
        cout << "Queue empty! Cannot dequeue element." << endl;
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return value;
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
void enqueue(Node *&front, Node *&rear, int value)
{
    Node *nodeToBeInserted = new Node(value);
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