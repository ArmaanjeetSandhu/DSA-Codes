#include <iostream>
using namespace std;
class base1
{
public:
    void greet()
    {
        cout << "Hi" << endl;
    }
};
class base2
{
public:
    void greet()
    {
        cout << "Hello" << endl;
    }
};
class derived : public base1, public base2
{
    // Resolution of ambiguity between two base classes
public:
    void greet()
    {
        base1 ::greet();
    }
};
int main()
{
    derived d;
    d.greet();
    return 0;
}
// In the case of ambiguity between a base class and a derived class, the latter has higher precedence
// Multipath inheritance (particular form of hybrid inheritance)
// Ambiguity in multipath inheritance is resolved using virtual base class
#include <iostream>
using namespace std;
class Student
{
protected:
    int roll_no; // In class 'Total', roll_no will be inherited from both 'Academics' and 'Sports', leading to ambiguity and duplication. Hence, 'Student' is declared as a virtual base class while defining 'Academics' and 'Sports'
public:
    void set_number(int a)
    {
        roll_no = a;
    }
    void print_number()
    {
        cout << "Roll no.: " << roll_no << endl;
    }
};
class Academics : virtual public Student
{
protected:
    float maths, physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }
    void print_marks()
    {
        cout << "Total: " << endl
             << "Mathematics: " << maths << endl
             << "Physics: " << physics << endl;
    }
};
class Sports : virtual public Student
{
protected:
    float score;

public:
    void set_score(float sc)
    {
        score = sc;
    }
    void print_score(void)
    {
        cout << "Score: " << score << endl;
    }
};
class Total : public Academics, public Sports
{
private:
    float total;

public:
    void display(void)
    {
        total = maths + physics + score;
        print_number();
        print_marks();
        print_score();
        cout << "Total: " << total << endl;
    }
};
int main()
{
    Total x;
    x.set_number(1010);
    x.set_marks(23, 46);
    x.set_score(5);
    x.display();
    return 0;
}