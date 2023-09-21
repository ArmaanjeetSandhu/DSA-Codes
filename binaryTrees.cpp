/*
internal node: node with atleast one child
depth of a node: number of edges from the root to node
height of a node: number of edges from node to the deepest leaf
degree of a node: number of children of node
degree of a tree: highest degree of a node of the tree
ancestors: parents, parents of parents, and so on
descendants: children, children of children, and so on
*/

// Binary Tree: tree whose degree <= 2

/*
Types of Binary Trees:
1. Full a.k.a. strict a.k.a. proper: Every node has either zero or two children
2. Perfect: Full binary tree in which all levels are completely filled.
3. Complete: All levels are completely filled, except possibly for the last level, which is filled from left to right.
4. Degenerate: Each parent has exactly one child; the tree resembles a linked list
5. Skewed: All nodes have only one child, either to the left or to the right
    Left-skewed: All nodes have only a left child.
    Right-skewed: All nodes have only a right child.
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
Node *buildDepthWise(Node *root)
{
    int data;
    cout << "data: ";
    cin >> data;
    if (data == -1)
        return NULL;
    root = new Node(data);
    cout << "For the node to the left of \"" << data << "\", ";
    root->left = buildDepthWise(root->left);
    cout << "For the node to the right of \"" << data << "\", ";
    root->right = buildDepthWise(root->right);
    return root;
}
void buildBreadthWise(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Data for root: ";
    cin >> data;
    if (data == -1)
        return;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int left;
        cout << "For the node to the left of \"" << q.front()->data << "\", data: ";
        cin >> left;
        if (left != -1)
        {
            temp->left = new Node(left);
            q.push(temp->left);
        }
        int right;
        cout << "For the node to the right of \"" << q.front()->data << "\", data: ";
        cin >> right;
        if (right != -1)
        {
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
}
void levelOrderBasic(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty tree!" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << " ";
        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
}
void levelOrderNewLine(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i)
        {
            cout << q.front()->data << " ";
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        cout << endl;
    }
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }
    else
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }
    else
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}
void printCurrentLevel(Node *root, int level)
{
    if (root == NULL || level == 0)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
// void levelOrder(Node *root)
// {
//     int h = height(root);
//     int i;
//     for (i = 1; i <= h; i++)
//         printCurrentLevel(root, i);
// }