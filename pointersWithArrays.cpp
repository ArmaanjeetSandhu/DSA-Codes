/*
When you declare an integer array 'arr', the name 'arr' itself also represents a pointer to the first element of the array
However, 'arr' is a constant pointer and not a regular pointer. Hence, statements like arr++ are not valid.
Also, &arr and &arr[0] are the same and refer to the address of the first element of the array
*/
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {42, 34, 45, 98, 77};
    int *ptr = arr;
    cout << "arr[0] = " << *ptr << endl;       // ALITER: ptr[0]
    cout << "arr[1] = " << *(ptr + 1) << endl; // ALITER: ptr[1]
    return 0;
}

/*
When you declare a character array 'str', the name 'str' itself also represents a pointer to the first element of the array
*/
#include <iostream>
using namespace std;
int main()
{
    char str[] = "Hello";
    char *ptr = str;

    printf("%p \n", str); // or &str or &str[0]
    cout << &str << endl; // equivalent to printf("%p \n", str);
    cout << endl;

    printf("%s \n", str);    // or &str[0] (but not &str)
    cout << str << endl;     // equivalent to printf("%s \n", str);
    cout << &str[0] << endl; // equivalent to printf("%s \n", str);
    cout << ptr << endl;     // equivalent to printf("%s \n", str);
    cout << endl;

    while (*ptr != '\0')
        cout << ptr++ << endl;

    return 0;
}