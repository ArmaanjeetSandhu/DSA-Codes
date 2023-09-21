#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void fibonacciUpto(int n)
{
    int a = 0, b = 1;
    cout << a << " " << b << " ";
    for (int i = 1; i < n; i++)
    {
        int nextNumber = a + b;
        cout << nextNumber << " ";
        a = b;
        b = nextNumber;
    }
}
bool isPrimeBasic(int n)
{
    if (n <= 0 || n == 1 || n == 2)
        return false;
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}
void spellNumber(int n)
{
    vector<string> v1;
    while (n != 0)
    {
        int digit = n % 10;
        switch (digit)
        {
        case 1:
            v1.push_back("One");
            break;
        case 2:
            v1.push_back("Two");
            break;
        case 3:
            v1.push_back("Three");
            break;
        case 4:
            v1.push_back("Four");
            break;
        case 5:
            v1.push_back("Five");
            break;
        case 6:
            v1.push_back("Six");
            break;
        case 7:
            v1.push_back("Seven");
            break;
        case 8:
            v1.push_back("Eight");
            break;
        case 9:
            v1.push_back("Nine");
            break;
        }
        n /= 10;
    }
    reverse(v1.begin(), v1.end());
    if (!v1.empty())
    {
        for (string i : v1)
            cout << i << " ";
        cout << endl;
    }
}
int powerRecursive(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int ans = powerRecursive(a, b / 2);
    if (b % 2 == 0)
        return ans * ans;
    else
        return a * ans * ans;
}