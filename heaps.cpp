/*
A heap is a complete binary tree that satisfies the heap property.
1. Max heap: Every node is greater than or equal to its descendants
2. Min heap: Every node is lesser than or equal to its descendants
*/
/*
In a heap, if a node lies at index i, then its left child lies at index 2i, right child at index 2i+1, and parent at index i/2
*/
#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
class heap
{
public:
    int *arr;
    int size = 0;
    heap()
    {
        this->size = 0;
        arr = new int[size + 1];
    }
    heap(int size)
    {
        this->size = size;
        arr = new int[size];
    }
};
void insertIntoMaxHeap(heap *&h, int data)
{
    h->size++;
    h->arr[h->size] = data;
    int current = h->size;
    while (current > 1 && data > h->arr[current / 2])
    {
        swap(h->arr[current], h->arr[current / 2]);
        current /= 2;
    }
}
void insertIntoMinHeap(heap *&h, int data)
{
    h->size++;
    h->arr[h->size] = data;
    int current = h->size;
    while (current > 1 && data < h->arr[current / 2])
    {
        swap(h->arr[current], h->arr[current / 2]);
        current /= 2;
    }
}
void buildMaxHeap(heap *&h)
{
    int data;
    cout << "Enter value of node to be inserted ";
    cin >> data;
    while (data != -1)
    {
        insertIntoMaxHeap(h, data);
        cout << "Enter value of node to be inserted ";
        cin >> data;
    }
}
void buildMinHeap(heap *&h)
{
    int data;
    cout << "Enter value of node to be inserted ";
    cin >> data;
    while (data != -1)
    {
        insertIntoMinHeap(h, data);
        cout << "Enter value of node to be inserted ";
        cin >> data;
    }
}
void deleteRootNodeFromMaxHeap(heap *&h)
{
    h->arr[1] = h->arr[h->size];
    h->size--;
    int current = 1;
    while (current < h->size)
    {
        int leftIndex = 2 * current, rightIndex = 2 * current + 1;
        if (leftIndex < h->size && h->arr[current] < h->arr[leftIndex])
        {
            swap(h->arr[current], h->arr[leftIndex]);
            current = leftIndex;
        }
        else if (rightIndex < h->size && h->arr[current] < h->arr[rightIndex])
        {
            swap(h->arr[current], h->arr[rightIndex]);
            current = rightIndex;
        }
    }
}
void display(heap *h)
{
    for (int i = 1; i <= h->size; i++)
        cout << h->arr[i] << " ";
    cout << endl;
}
/*
The heapify algorithm is used to transform an array into a heap
In a complete binary tree of n nodes, the nodes from the (n/2 + 1)th index to the nth index are all leaf nodes
Since each leaf node is a heap in itself, we only need to consider nodes numbered 1 to n/2 for the heapify algorithm
*/
void heapify(int *arr, int n, int i)
{
    int largest = i, left = 2 * i, right = 2 * i + 1;
}
int main()
{
    heap *h = new heap();
    buildMaxHeap(h);
    display(h);
    return 0;
}