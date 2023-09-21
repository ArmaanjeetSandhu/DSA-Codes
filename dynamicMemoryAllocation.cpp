// For primitive data types
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter space-separated values for n and m: " << endl;
    cin >> n >> m;

    int a = 4; // memory is statically allocated for this integer
    int *ptr1 = &a;
    cout << "The value at address ptr1 is " << *ptr1 << "." << endl;

    int *ptr2 = new int(5); // memory is dynamically allocated for this integer, which is initialized to 5
    cout << "The value at address ptr2 is " << *ptr2 << "." << endl;

    int *ptr3 = new int[n]; // memory is dynamically allocated for this integer array of size n
    // If we were to create a static array, the size would be determined at runtime, instead of compile time, because the size is given by the user as input
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Enter the value of [" << i << "]: " << endl;
        cin >> ptr3[i];
    }
    for (int i = 0; i < n; i++)
        cout << "The value of [" << i << "] of this dynamic array is " << ptr3[i] << "." << endl;
    delete[] ptr3;
    ptr3 = NULL;

    int **ptr4 = new int *[n]; // memory is dynamically allocated for this matrix (2-D array)
    for (int i = 0; i < n; i++)
        ptr4[i] = new int[m];
    // So, the matrix is an array of n elements where each element is an integer pointer pointing to a dynamic array of size m. Hence, n = number of rows and m = number of columns
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter the value of [" << i << "][" << j << "]: " << endl;
            cin >> ptr4[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ptr4[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] ptr4[i];
        ptr4[i] = NULL;
    }
    delete[] ptr4;
    ptr4 = NULL;

    return 0;
}