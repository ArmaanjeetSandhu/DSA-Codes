// Vector
#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> v)
{
    if (!v.empty()) // if vector is not empty
    {
        cout << "Elements of vector: ";
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
}
int main()
{
    vector<int> v;
    vector<char> v1(5, '*'); // vector of size 5 with each element initialized to '*'
    vector<int> v2(v);       // v2 is a copy of v
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl; // Capacity of a fully occupied vector doubles on addition of a new element
    cout << "Element at index 2: " << v.at(2) << endl;
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
    display(v);
    v.erase(v.begin() + 1, v.begin() + 3); // removes range of elements
    if (!v.empty())                        // if vector is not empty
    {
        cout << "Elements of vector: ";
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl; // size changes, but capacity remains same
    v.pop_back();                                           // removes last element
    v.clear();                                              // erases all elements (size becomes 0, but capacity remains same)
    return 0;
}

// Priority Queue
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> p1; // max heap (by default)
    p1.push(7);
    p1.push(2);
    p1.push(5);
    p1.push(1);
    int n = p1.size();
    for (int i = 0; i < n; i++)
    {
        cout << p1.top() << " ";
        p1.pop();
    }
    cout << endl;
    priority_queue<int, vector<int>, greater<int>> p2; // min heap
    p2.push(7);
    p2.push(2);
    p2.push(5);
    p2.push(1);
    int x = p2.size();
    for (int i = 0; i < n; i++)
    {
        cout << p2.top() << " ";
        p2.pop();
    }
    cout << endl;
    return 0;
}

// Set
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(7);
    s.insert(2);
    s.insert(5);
    s.insert(5); // ignored because repeated elements are not permitted in a set
    s.insert(1);
    for (int i : s)
        cout << i << " ";
    cout << endl;
    cout << s.count(7);  // indicates if an element is present or not
    auto it = s.find(5); // iterator where the element '5' is present
    return 0;
}

// Map
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> m;
    m[11] = "apple";
    m.insert({33, "banana"});
    m[22] = "orange";
    for (auto i : m)
        cout << i.first << " "; // i.first represents the key
    cout << endl;
    for (auto i : m)
        cout << i.second << " "; // i.second represents the value
    cout << endl;
    auto it = m.begin();
    for (auto i = it; i != m.end(); i++)
        cout << i->first << endl;
    return 0;
}

// Algorithms
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
int main()
{
    array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    cout << binary_search(arr.begin(), arr.end(), 6); // checks if 6 is present or not
    return 0;
}