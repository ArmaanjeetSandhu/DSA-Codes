/*
It is not necessary to have a head pointer when working with circular linked lists; using the tail pointer is sufficient. If any node is denoted as the "head", it can easily be accessed using the tail pointer.
*/

// Singly linked
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
        this->next = this;
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
void display(Node *tail)
{
    if (tail == NULL)
        cout << "Empty linked list!" << endl;
    else
    {
        Node *temp = tail->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
}
void insertAfterNodeWithValue(Node *&tail, int value, int data)
{
    Node *nodeToInsert = new Node(data);
    if (tail == NULL)
        tail = nodeToInsert;
    else
    {
        Node *temp = tail->next;
        while (temp != tail && temp->data != value)
            temp = temp->next;
        if (temp == tail && temp->data != value)
        {
            cout << "Value not found in the list." << endl;
            delete nodeToInsert;
            return;
        }
        else
        {
            nodeToInsert->next = temp->next;
            temp->next = nodeToInsert;
            if (tail->next == nodeToInsert)
                tail = nodeToInsert;
        }
    }
}
void deleteNodeGivenValue(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "Empty linked list" << endl;
        return;
    }
    Node *prev = NULL;
    Node *temp = tail->next;
    while (temp != tail && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == tail && temp->data != value)
    {
        cout << "Value not found in the list." << endl;
        return;
    }
    if (temp == tail && temp->next == tail)
    {
        delete temp;
        tail = NULL;
        return;
    }
    if (temp == tail->next)
    {
        tail->next = temp->next;
        delete temp;
    }
    else
    {
        prev->next = temp->next;
        if (temp == tail)
            tail = prev;
        delete temp;
    }
}
int getLength(Node *tail)
{
    if (tail == NULL)
        return 0;
    int length = 1;
    Node *temp = tail->next;
    while (temp != tail)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
// Doubly linked
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = this;
        this->prev = this;
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