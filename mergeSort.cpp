#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void mergeTwoSortedArrays(int a[], int b[], int c[], int m, int n)
// for merging two sorted arrays into one sorted array
// m = size of a, n = size of b
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < m)
        c[k++] = a[i++];
    while (j < n)
        c[k++] = b[j++];
}
void mergeTwoSortedSubarrays(int arr[], int low, int mid, int high)
// mid points to the last element of the first sub-array, high points to last element of the array
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    while (i <= mid)
        b[k++] = arr[i++];
    while (j <= high)
        b[k++] = arr[j++];
    for (int i = low; i <= high; i++)
        arr[i] = b[i];
}
void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeTwoSortedSubarrays(arr, low, mid, high);
    }
}
int main()
{
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    mergeSort(arr, 0, 6);
    printArray(arr, n);
    return 0;
}