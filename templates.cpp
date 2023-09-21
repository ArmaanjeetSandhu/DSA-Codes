// Class template
#include <iostream>
using namespace std;
template <class T> // We now have a blueprint for a class such that any data type can be in the place of 'T'
class vector
{
    public:
        T *arr;
        int size;
        vector(int m)
        {
            size = m;
            arr = new T[size];
        }
        T dotProduct(vector &v)
        {
            int d = 0;
            for (int i = 0; i < size; i++)
            {
                d += this->arr[i] * v.arr[i];
            }
            return d;
        }
        
};
int main()
{
    vector <int> v1(3);
    vector <int> v2(3);
    v1.arr[0] = 4;
    v1.arr[1] = 3;
    v1.arr[2] = 1;
    v2.arr[0] = 1;
    v2.arr[1] = 0;
    v2.arr[2] = 1;
    int smile = v1.dotProduct(v2);
    cout << smile << endl;
    return 0;
}
// Class template with multiple parameters
#include <iostream>
using namespace std;
template <class T1, class T2>
class myClass
{
    public:
        T1 data1;
        T2 data2;
        myClass(T1 a, T2 b)
        {
            data1 = a;
            data2 = b;
        }
        void display()
        {
        cout<<this->data1<<" and "<<this->data2;
    }
};
int main()
{
    myClass <int, char> obj(1, 'c');
    obj.display();
    return 0;
}
// Class template with default parameters
#include <iostream>
using namespace std;
template <class T1 = int, class T2 = float> // by default, T1 is int and T2 is float
class hash
{
    public:
        T1 p;
        T2 q;
        hash(T1 x, T2 y)
        {
            p = x;
            q = y;
        }
        void show()
        {
            cout << p << " and " << q << endl;
        }
};
int main()
{
    hash <> h(4, 6.4);
    h.show();
    return 0;
}
// Function template
#include <iostream>
using namespace std;
template <class T1, class T2>
float avg(T1 a, T2 b)
{
    float x = (a+b)/2;
    return x;
}
int main()
{
    int a = 8; double b = 2.500;
    cout << avg(a, b);
    return 0;
}
// Member function template
#include <iostream>
using namespace std;
template <class T>
class scotch
{
    public:
        T a;
        scotch(T x)
        {
            a = x;
        }
        void display();
};
template <class T>
void scotch<T> :: display()
{
    cout<<a<<endl;
}
int main()
{
    scotch <int> kilt(35);
    kilt.display();
    return 0;
}
// Ambiguity in templates
#include <iostream>
using namespace std;
template <class T>
void func(T a)
{
    cout<<"Template function called, and parameter of func() is "<<a<<endl;
}
void func(int a)
{
    cout<<"Regular function called, and parameter of func() is "<<a<<endl;
}
int main()
{
    int x = 99;
    func(99); // Exact match of function has higher priority than template function
    return 0;
}