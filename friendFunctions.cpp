// Example 1
#include <iostream>
using namespace std;
class Complex
{
    int a, b;
    friend Complex sumComplex(Complex o1, Complex o2);
    // Since sumComplex() has been declared as a friend function, it can access the private variables of Complex. If Complex had any protected members, those would be accessible too. However, sumComplex() is still not a member function of Complex.
public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void printNumber()
    {
        cout << "The complex number is " << a << " + " << b << "i" << endl;
    }
};
Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main()
{
    Complex c1, c2, sum;
    c1.setNumber(1, 4);
    c1.printNumber();
    c2.setNumber(5, 8);
    c2.printNumber();
    sum = sumComplex(c1, c2);
    sum.printNumber();
    return 0;
}
// Example 2
#include <iostream>
using namespace std;
class Complex; // forward declaration
class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumRealComplex(Complex, Complex);
    // This function has not been defined since the dfinition involves Complex which has so far not been defined
    // This is also why we had to opt for the forward declaration of Complex (so that sumRealComplex() could have arguments)
};
class Complex
{
    int a, b;
    friend int Calculator ::sumRealComplex(Complex o1, Complex o2);

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void printNumber()
    {
        cout << "The complex number is " << a << " + " << b << "i" << endl;
    }
};
int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}
int main()
{
    Complex c1, c2;
    c1.setNumber(1, 4);
    c2.setNumber(5, 8);
    Calculator calc;
    int res = calc.sumRealComplex(c1, c2);
    cout << "The real part of the sum of c1 and c2 is " << res << endl;
    return 0;
}
// Instead of declaring functions individually as friend functions, an entire class containing those functions can be declared, e.g., friend class Calculator;
// Friend class
#include <iostream>
using namespace std;
class A
{
    int x;

public:
    A()
    {
        x = 10;
    }
    friend class B; // This declaration makes private variables of A available to member functions of B
};
class B
{
public:
    void disp(A &t)
    {
        cout << t.x << endl;
    }
};
int main()
{
    A a;
    B b;
    b.disp(a);
}