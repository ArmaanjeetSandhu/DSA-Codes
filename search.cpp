#include <iostream>
#include <vector>
using namespace std;
int linearSearchIterative(vector<int> arr, int element)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
int linearSearchRecursive(vector<int> arr, int element, int index = 0)
{
    if (index > arr.size())
        return -1;
    if (arr[index] == element)
        return index;
    return linearSearchRecursive(arr, element, ++index);
}
int binarySearchIterative(vector<int> arr, int element)
{
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2; // which is the same as (low + high) / 2
        // The above expression was used to avoid signed integer overflow
        if (arr[mid] == element)
            return mid;
        if (arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int binarySearchRecursive(vector<int> arr, int low, int high, int element)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == element)
            return mid;
        if (arr[mid] < element)
            return binarySearchRecursive(arr, mid + 1, high, element);
        else
            return binarySearchRecursive(arr, low, mid - 1, element);
    }
    return -1;
}
int sqrtUsingBinarySearch(int n)
{
    int low = 0, high = n, mid, ans;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid == n)
            ans = mid;
        if (mid * mid < n)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return ans;
}