// Single inheritance
#include <iostream>
using namespace std;
class Employee
{
public:
    int id;
    double salary;
    Employee(){}; // If a parameterized constructor is declared in the base class, then declaration of default constructor is also required
    Employee(int a)
    {
        id = a;
        salary = 34000.0;
    }
};
class Programmer : public Employee
{
    char language[10];

public:
    Programmer(int a)
    {
        id = a;
    }
};
int main()
{
    Employee e1(1);
    Programmer p1(1);
    cout << e1.salary << endl; // cout << p1.id << endl; will not return p1's id since id is a private variable (because it has been inherited from Employee base class)
    return 0;
}
// Multilevel inheritance
#include <iostream>
using namespace std;
class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int);
    void get_roll_number();
};
void Student ::set_roll_number(int r)
{
    roll_number = r;
}
void Student ::get_roll_number()
{
    cout << "Roll number: " << roll_number << endl;
}
class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};
void Exam ::set_marks(float m1, float m2)
{
    maths = m1;
    physics = m2;
}
void Exam ::get_marks()
{
    cout << "Marks in Mathematics: " << maths << endl;
    cout << "Marks in Physics: " << physics << endl;
}
class Result : public Exam
{
    float percentage;

public:
    void display_results()
    {
        get_roll_number();
        get_marks();
        cout << "Result: " << (maths + physics) / 2 << "%" << endl;
    }
};
int main()
{
    Result a;
    a.set_roll_number(420);
    a.set_marks(94.0, 90.0);
    a.display_results();
    return 0;
}
// Multiple inheritance
#include <iostream>
using namespace std;
class A
{
public:
    void greeting();
};
void A ::greeting()
{
    cout << "Hi!" << endl;
}
class B
{
public:
    void greeting();
};
void B ::greeting()
{
    cout << "Hello!" << endl;
}
class C : public A, public B
{
public:
    C();
    int a;
};
C ::C()
{
    int a = 69;
}
int main()
{
    C c1;
    // c1.greeting(); will not execute due to multiple inheritance ambiguity
    c1.A::greeting();
    c1.B::greeting();
    return 0;
}