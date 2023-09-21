/*
Approaches to dynamic programming:
1. Top down (recursion + memoization)
2. Bottom up (tabulation)
*/

// nth element of Fibonacci sequence using top-down approach
#include <iostream>
#include <vector>
using namespace std;
int fib(int n)
{
    vector<int> dp(n + 1);
    for (int i = 0; i < dp.size(); i++)
        dp[i] = -1;
    if (n == 0 || n == 1)
        return n;
    for (int i = 0; i < n; i++)
    {
        dp[i] = fib(n - 1) + fib(n - 2);
    }
    
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    return 0;
}