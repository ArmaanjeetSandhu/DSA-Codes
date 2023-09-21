/*
Graph Representations
1. Adjacency list: Mark nodes with the list of its neighbours
2. Adjacency matrix:
    Enter 1 if there is an edge between nodes, 0 otherwise (for undirected graphs)
    Enter 1 if there is an edge from one node to another, 0 otherwise (for directed graphs)
3. Cost adjacency matrix: Enter weight of edge if an edge exists, 0 otherwise (-1 if weight of any edge is zero)
4. Incidence matrix: Enter 1 if edge is incident on vertex, 0 if not, and 2 if the edge is a loop
*/

// Adjacency list using an unordered map
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
template <typename T> // ALITER: template <class T>
class graph
{
    public:
        unordered_map<T, vector<T>> adjList;
        void addEdge(T u, T v, bool directed)
        {
            adjList[u].push_back(v);
            if (directed == 0)
                adjList[v].push_back(u);
        }
        void display()
        {
            for (auto i : adjList)
            {
                cout << i.first << " -> ";
                for (auto j : i.second)
                    cout << j << " ";
                cout << endl;
            }
        }
};
int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    graph<int> g;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.display();
    return 0;
}

/* Breadth First Search (BFS) Traversal
Implemented using queues
Can start with any vertex
Multiple results of BFS possible
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
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue full! %d cannot be inserted", val);
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 10; // arbitrarily selected
    q.f = q.r = -1; // that means queue is empty
    q.arr = (int *)malloc(q.size * sizeof(int)); // 
    int u;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adjacency_matrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // enqueue for explored node
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (adjacency_matrix[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}