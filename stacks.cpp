// Stack using array
#include <iostream>
using namespace std;
class Stack
{
    int size;
    int top;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    int isFull()
    {
        if (top == size - 1)
            return 1;
        else
            return 0;
    }
    void push(int val)
    {
        if (isFull())
            cout << "Stack Overflow! " << val << " cannot be pushed." << endl;
        else
        {
            top++;
            arr[top] = val;
        }
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack Underflow! pull() operation cannot be performed." << endl;
        else
            top--;
    }
    int peek()
    {
        if (!isEmpty())
            return arr[top];
        else
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
};
// Stack using linked list
#include <iostream>
using namespace std;
