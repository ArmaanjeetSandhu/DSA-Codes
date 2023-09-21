#include <iostream>
#include <climits>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void reverseIterative(int *arr, int size)
{
    for (int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - i - 1]);
}
void reverseRecursive(int *arr, int i, int j)
{
    if (i > j)
        return;
    swap(arr[i++], arr[j--]);
    reverseRecursive(arr, i, j);
}
int insertion(int *arr, int size, int element, int capacity, int index)
{
    if (size >= capacity)
        return -1;
    for (int i = size - 1; i >= index; i--)
        arr[i + 1] = arr[i];
    arr[index] = element;
    return 1;
}
void deletion(int *arr, int size, int index)
{
    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];
}
void update(int *arr, int size)
{
    arr[2] = 7;
    // arr[2] outside the function will also be updated
    // This is because the function call is update(arr, size) and arr is the same as &arr[0]
}
bool isSortedIterative(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}
bool isSortedRecursive(int *arr, int size)
{
    if (size == 0 || size == 1)
        return 1;
    if (arr[0] > arr[1])
        return 0;
    return isSortedRecursive(arr + 1, size - 1);
}
int containsDuplicate(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                return 1;
        }
    }
    return 0;
}
int maxSumContiguousSubarray(int *arr, int size)
// Contiguous = elements are consecutive and in order
// Kadane's Algorithm --> O(n)
{
    int max_sum = INT_MIN;
    int current_sum = 0;
    for (int i = 0; i < size; i++)
    {
        current_sum += arr[i];
        if (current_sum > max_sum)
            max_sum = current_sum;
        if (current_sum < 0)
            current_sum = 0;
    }
    return max_sum;
}
int maximumOfTwo(int a, int b)
{
    return (a > b) ? a : b;
}
int maximumOfThree(int a, int b, int c)
{
    return maximumOfTwo(maximumOfTwo(a, b), c);
}
int maxCrossingSum(int *arr, int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return maximumOfThree(left_sum + right_sum - arr[m], left_sum, right_sum);
}
int maxSubArraySum(int *arr, int l, int h)
{
    if (l > h)
        return INT_MIN;
    if (l == h)
        return arr[l];
    int m = (l + h) / 2;
    return maximumOfThree(maxSubArraySum(arr, l, m - 1), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}