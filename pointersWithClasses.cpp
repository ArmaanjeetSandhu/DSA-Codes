/*
For pointers with custom data types, we require a constructor
*/

// Pointers to objects
#include <iostream>
using namespace std;
class complex
{
    int real, imaginary;

public:
    void setval(int a, int b)
    {
        real = a;
        imaginary = b;
    }
    void getval()
    {
        cout << "The number is " << real << " + " << imaginary << "i." << endl;
    }
};
int main()
{
    complex x;
    complex *ptr = &x;
    (*ptr).setval(3, 4); // Alternatively, ptr->setval(3, 4);
    (*ptr).getval();     // Alternatively, ptr->getval(3, 4);
    return 0;
}
// this pointer
#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A &setData(int a)
    {
        this->a = a;
        return *this; // 'this' pointer is also used to return a reference to the object that invokes a member function of the class it belongs to
    }
    void getData()
    {
        cout << "a = " << a << endl;
    }
};
int main()
{
    A obj;
    obj.setData(4).getData();
    return 0;
}
// Pointers to derived class
#include <iostream>
using namespace std;
class BaseClass
{
public:
    int var_base;
    void display()
    {
        cout << "Dispalying Base class variable var_base " << var_base << endl;
    }
};
class DerivedClass : public BaseClass
{
public:
    int var_derived;
    void display()
    {
        cout << "Dispalying Base class variable var_base " << var_base << endl;
        cout << "Dispalying Derived class variable var_derived " << var_derived << endl;
    }
};
int main()
{
    BaseClass *base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;
    base_class_pointer = &obj_derived; // pointing base class pointer to object of derived class
    base_class_pointer->var_base = 34;
    base_class_pointer->display(); // The output so received will be because the pointer is of the base class, so display() of BaseClass is invoked. If however, display() of BaseClass is declared as a virtual function, then this statement will invoke display() of DerivedClass
    // obj_derived.display(); will invoke display() of DerivedClass
    // base_class_pointer->var_defined = 65; is not allowed because the pointer is of the base class, not the derived class
    return 0;
}
/*
Pure virtual function: A function in a base class that demands its redefinition in a derived class, and is created only for its namesake in the derived class to be invoked
In the above example, it would be declared as --> virtual void display() = 0;
Abstract base class: A class that contains a pure virtual function, and is created only for other classes to be derived from it
*/