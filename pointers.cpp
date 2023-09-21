/*
A pointer variable always takes the same amount of storage (8 bytes) regardless of the data type.
*/
#include <iostream>
using namespace std;
void swap(int x, int y) // call by value (values of x and y are swapped only within the scope of the function)
{
    int temp = x;
    x = y;
    y = temp;
} // function call --> swap(a, b)
void swap(int *x, int *y) // call by reference using pointers
{
    int temp = *x;
    *x = *y;
    *y = temp;
} // function call --> swap(&a, &b)
void swap(int &x, int &y) // call by reference using reference variables
{
    int temp = x;
    x = y;
    y = temp;
} // function call --> swap(a, b)
int main()
{
    int p = 7;
    int *q = &p; // since p is int, q must be int*
    return 0;
}

// Double pointers
#include <iostream>
using namespace std;
void update1(int x) // call by value, no global changes whatsoever
{
    x += 1;
}
void update2a(int *px) // call by value, no global changes whatsoever
{
    px += 1;
}
void update2b(int *px) // increases p, but all addresses remain the same
{
    *px += 1;
}
void update3a(int **ppx) // call by value, no global changes whatsoever
{
    ppx += 1;
}
void update3b(int **ppx) // increases the value of px, i.e., the address of p
{
    *ppx += 1;
}
void update3c(int **ppx) // increases p, but all addresses remain the same
{
    **ppx += 1;
}
int main()
{
    int x = 45;
    int *px = &x;
    int **ppx = &px;

    cout << "x = " << x << endl;
    cout << "px = " << px << endl;
    cout << "ppx = " << ppx << endl;

    update2b(px);
    cout << "update2b(): "
         << "x = " << x << endl;
    cout << "update2b(): "
         << "px = " << px << endl;
    cout << "update2b(): "
         << "ppx = " << ppx << endl;

    update3b(ppx);
    cout << "update3b(): "
         << "x = " << x << endl;
    cout << "update3b(): "
         << "px = " << px << endl;
    cout << "update3b(): "
         << "ppx = " << ppx << endl;

    update3c(ppx);
    cout << "update3c(): "
         << "x = " << x << endl;
    cout << "update3c(): "
         << "px = " << px << endl;
    cout << "update3c(): "
         << "ppx = " << ppx << endl;

    return 0;
}