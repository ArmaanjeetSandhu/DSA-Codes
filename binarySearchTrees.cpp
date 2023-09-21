/*
A BST is a binary tree with the following properties:
1. For every node, all nodes in the left subtree are lesser than it
2. For every node, all nodes in the right subtree are greater than it
3. Inorder traversal yields all elements sorted in ascending order
*/
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertNode(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    else
        cout << "Duplicate elements not allowed!" << endl;
    return root;
}
void build(Node *&root)
{
    int data;
    cout << "Enter value of node to be inserted ";
    cin >> data;
    while (data != -1)
    {
        root = insertNode(root, data);
        cout << "Enter value of node to be inserted ";
        cin >> data;
    }
}
Node *searchRecursive(Node *root, int key) // Space complexity: O(n)
{
    if (root == NULL)
        return NULL;
    if (key == root->data)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}
Node *searchIterative(Node *root, int key) // Space complexity: O(1)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node *findMax(Node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}
Node *inOrderPredecessor(Node *root, int key)
{
    Node *predecessor = NULL;
    while (root != NULL)
    {
        if (key < root->data)
            root = root->left;
        else if (key > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            if (root->left != NULL)
                predecessor = findMin(root->left);
            break;
        }
    }
    return predecessor;
}
Node *inOrderSuccessor(Node *root, int key)
{
    Node *successor = NULL;
    while (root != NULL)
    {
        if (key < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (key > root->data)
            root = root->right;
        else
        {
            if (root->right != NULL)
                successor = findMin(root->right);
            break;
        }
    }
    return successor;
}
Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
        return NULL;
    Node *predecessor;
    if (root->data == value)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            Node *successor = inOrderSuccessor(root, root->data);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
            return root;
        }
        /*
        ALLITER:
        if (root->left != NULL && root->right != NULL)
        {
            Node *predecessor = inOrderPredecessor(root, root->data);
            root->data = predecessor->data;
            root->left = deleteNode(root->left, predecessor->data);
            return root;
        }
        */
    }
    else if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, value);
        return root;
    }
}