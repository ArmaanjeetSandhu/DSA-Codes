/*
Best Case: O(n) --> when the array is already sorted
Worst Case: O(n^2) --> when the array is sorted in the order opposite to the required order
Average Case: O()
*/
// Insertion sort is a stable algorithm
#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}
int main()
{
    int abc[] = {12, 54, 65, 7, 23, 9};
    insertionSort(abc, 6);
    printArray(abc, 6);
    return 0;
}