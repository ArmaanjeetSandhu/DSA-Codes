#include <iostream>
#include <map>
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
        this->next = NULL;
        this->prev = NULL;
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
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int position, int data) // NOTE: position != index
{
    Node *temp = head;
    if (position == 1)
        insertAtHead(head, tail, data);
    else
    {
        for (int i = 1; i <= position - 2; i++)
            temp = temp->next;
        if (temp->next == NULL)
            insertAtTail(tail, data);
        else
        {
            Node *nodeToInsert = new Node(data);
            nodeToInsert->next = temp->next;
            temp->next->prev = nodeToInsert;
            nodeToInsert->prev = temp;
            temp->next = nodeToInsert;
        }
    }
}
void deleteFromHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Empty linked list!" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    head->prev = NULL;
    delete temp;
    if (head == NULL)
        tail = NULL;
}
void deleteNodeGivenPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
        deleteFromHead(head, tail);
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        if (curr == tail)
            tail = prev;
        curr->next = NULL;
        delete curr;
    }
}
void deleteNodeGivenValue(Node *&head, Node *&tail, int val)
{
    if (head == NULL)
    {
        cout << "Empty linked list!" << endl;
        return;
    }
    if (head->data == val)
    {
        deleteFromHead(head, tail);
        return;
    }
    Node *prev = head;
    while (prev->next != NULL && prev->next->data != val)
        prev = prev->next;
    if (prev->next == NULL)
    {
        cout << "Value not found in the linked list!" << endl;
        return;
    }
    Node *curr = prev->next;
    prev->next = curr->next;
    curr->next->prev = prev;
    if (curr == tail)
        tail = prev;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}
Node *reverseIterative(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        curr->prev = forward;
        prev = curr;
        curr = forward;
    }
    return prev;
}
Node *reverseRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *reversedTail = reverseRecursive(head->next);
    head->next->next = head;
    head->next->prev = NULL;
    head->prev = head->next;
    head->next = NULL;
    return reversedTail;
}
int getLength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}