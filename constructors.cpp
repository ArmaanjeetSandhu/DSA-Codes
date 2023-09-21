// A constructor is a member function with the same name as of the class. It is used to initialize objects, and is automatically invoked whenever an object is created.
#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    Complex(); // declaring a constructor (should always be public)
    void printData()
    {
        cout << "The complex number is " << a << " + " << b << "i." << endl;
    }
};
Complex ::Complex() // Since there are no parameters, this is a default constructor, i.e., a = 0 and b = 0 by default whenever an object is created
{
    a = 0;
    b = 0;
}
int main()
{
    Complex c1;
    c1.printData();
    return 0;
}
// Parameterized constructor
#include <iostream>
using namespace std;
class num
{
    int a, b, c;

public:
    num(int, int, int);
    void printData()
    {
        cout << "The numbers are " << a << ", " << b << " and " << c << endl;
    }
};
num ::num(int x, int y, int z = 10)
{
    a = x;
    b = y;
    c = z;
} 
// ALternatively, num :: num(int x, int y, int z = 10) : a(x), b(y), c(z) {} (this is called an initialization list, and is only used with constructors)
int main()
{
    num c1(4, 6);          // implicit calling of function
    num c2 = num(5, 7, 8); // explicit calling of function
    c1.printData();
    c2.printData();
    return 0;
}
/* Similar to function overloading, constructor overloading (more than one constructor for the same class) is also observed */
// Copy constructor
#include <iostream>
using namespace std;
class number
{
    int integer;

public:
    number()
    {
        integer = 100;
    }
    number(int a)
    {
        integer = a;
    }
    number(number &object) // copy constructor
    {
        integer = object.integer;
        cout << "Copy constructor called: ";
    }
    void display()
    {
        cout << integer << endl;
    }
};
int main()
{
    number x1(50), x3;
    x1.display();
    number x2(x1);
    x2.display(); // If the copy constructor were not declared, a default copy constructor declared automatically would have been invoked, giving 100 as the output. This is called shallow copy.
    x3 = x1;      // The copy constructor is not invoked since x3 has not been created in this line; it has only been initialized using the assignment operator. This is also an example of shallow copy.
    x3.display();
    number x4 = x1; // copy constructor invoked; deep copy
    x4.display();
    return 0;
}
// Constructors in derived class
#include <iostream>
using namespace std;
class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Constructor of Base 1 called" << endl;
    }
    void printDataBase1()
    {
        cout << "The value of data1 is " << data1 << endl;
    }
};
class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Constructor of Base2 called" << endl;
    }
    void printDataBase2()
    {
        cout << "The value of data2 is " << data2 << endl;
    }
};
class Derived : public Base2, public Base1
{
    int derived1, derived2;

public:
    Derived(int a, int b, int c, int d) : Base1(a), Base2(b)
    {
        derived1 = c;
        derived2 = d;
        cout << "Constructor of Derived called" << endl;
    }
    void printDataDerived()
    {
        cout << "The value of derived1 is " << derived1 << endl;
        cout << "The value of derived2 is " << derived2 << endl;
    }
};
int main()
{
    Derived abc(1, 2, 3, 4);
    abc.printDataBase1();
    abc.printDataBase2();
    abc.printDataDerived();
    return 0;
}