#include <iostream>
using namespace std;
class Employee
{
private:
    int a, b;
    static int count; // static variable, initialized with 0 by default
    void setData2(int b1);

public:
    int c;
    void setData1(int a1);
    void getData()
    {
        setData2(10); // This is an example of nesting of member functions
        cout << "a = " << a << " (employee no. " << count << ")" << endl;
        cout << "b = " << b << " (employee no. " << count << ")" << endl;
        cout << "c = " << c << " (employee no. " << count << ")" << endl;
    }
    static void getCount() // static member function (can only access static variables)
    {
        cout << "The value of count is " << count << endl;
    }
};
int Employee ::count; // must be declared outside the class since it is static
void Employee ::setData1(int a1)
{
    a = a1;
    count++;
}
/*
ALITER:
void Employee :: setData1(int a)
{
    this->a = a;
    count++;
}
*/
void Employee ::setData2(int b1)
{
    b = b1;
}
/*
ALITER:
void Employee :: setData2(int b)
{
    this->b = b;
}
*/
int main()
{
    Employee Jack, John, Jill;
    Jack.setData1(5); // Jack.a = 5 is not allowed since 'a' is a private member
    Jack.c = 15;
    Jack.getData();
    Employee ::getCount();
    John.setData1(5);
    John.c = 15;
    John.getData();
    Employee ::getCount();
    Jill.setData1(5);
    Jill.c = 15;
    Jill.getData();
    Employee ::getCount();
    return 0;
}