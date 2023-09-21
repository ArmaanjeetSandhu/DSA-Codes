#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void bubbleSortAdaptive(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1);
        int isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}
int main()
{
    int abc[] = {12, 54, 65, 7, 23, 9};
    bubbleSort(abc, 6);
    printArray(abc, 6);
    return 0;
}