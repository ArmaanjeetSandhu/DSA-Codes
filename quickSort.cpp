/*
Best Case: O(n log(n)) --> when the array is randomly ordered or nearly randomly ordered and the pivot is the middle element (balanced recursion)
Worst Case: O(n^2) --> when the array is already sorted or nearly sorted and the pivot is either the first element or the last (unbalanced recursion)
Average Case: O(n log(n))
*/
// Random selection of pivot reduces the likelihood of selecting the smallest or largest element as the pivot element, thereby increasing the likelihood of balanced recursion
// QuickSort is an unstable algorithm
// QuickSort is an in-place algorithm, i.e., it requires no additional temporary storage space
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // or, int pivot = arr[high]
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[low], &arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high)
{
    int partitionIndex; // index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
int main()
{
    int arr[] = {9, 4, 7, 2, 6, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}