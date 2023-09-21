/*
break ---> brings the program out of the loop, i.e., out of 'for', 'while' or 'do-while' (if the loop is nested, the program is brought out of only the loop in which the break statement is given)
continue --> brings the program to the next iteration of the loop, i.e., any statements below 'continue' within the loop are ignored
*/

#include <iostream>
using namespace std;
int x = 45;
int main()
{
    int x = 65;
    cout << x << endl;
    cout << ::x << endl;

    cout << sizeof(65.5) << endl; // default data type of fractions is 'double'

    int a = 5;
    int b = a;  // b is initialized with the value of a
    int &c = a; // c is just another name for a (c is said to be a reference variable)

    const int p = 7; // the value of p cannot be changed
    p++;
    cout << p;

    return 0;
}

#include <iostream>
using namespace std;
int function(int a, int b)
{
    static int c = 13; // Since c is a static variable, this line will be run only once (no matter how many times function is called)
    return a * b + c++;
}
int main()
{
    int a = 1, b = 2;
    if (a-- > 0 || ++b > 2)
        cout << a << " and " << b << endl; // b = 2 because since the first part of the OR expression was satisfied, the second part was not read
    cout << function(a, b) << endl;
    cout << function(a, b) << endl;
    cout << function(a, b) << endl;
    return 0;
}

/*
Whenever a macro name is encountered by the compiler, it replaces the name with the definition of the macro. 
Unlike variables, macros do not need any storage and are immutable.
*/
#define PI 3.14 // macro
#include <iostream>
using namespace std;
/*
Inline functions are to functions what macros are to variables.
Unlike ordinary functions, inline functions cannot lead to function call overhead, and do not require storage to store the temporary variables created as part of the function call
Declaring a function as inline will work if the function has only one line its body, and may or may not work for 2-3 lines.
*/
inline int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int a = 1, b = 3;
    cout << max(a, b) << endl;
    return 0;
}