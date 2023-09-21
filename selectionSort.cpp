#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexOfMin])
                indexOfMin = j;
        }
        swap(arr[i], arr[indexOfMin]);
    }
}
int main()
{
    int abc[] = {12, 54, 65, 7, 23, 9};
    selectionSort(abc, 6);
    printArray(abc, 6);
    return 0;
}