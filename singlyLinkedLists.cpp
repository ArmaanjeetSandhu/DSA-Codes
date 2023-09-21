/*
It is not always necessary to have a tail pointer when working with linked lists. If you need to frequently work with the end of the list, adding a tail pointer can be a convenient optimization. If you use a tail pointer, make sure all operations on the linked list take the tail pointer into account.
*/

#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
        head = temp;
    }
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
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
    delete temp;
    if (head == NULL)
        tail = NULL;
}
void deleteNodeGivenPosition(Node *&head, Node *&tail, int position) // 'curr' = node to be deleted, 'prev' = node before curr
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
    if (curr == tail)
        tail = prev;
    curr->next = NULL;
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