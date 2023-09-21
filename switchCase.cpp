#include <iostream>
using namespace std;
int main()
{
    char button;
    cout << "Enter a character: ";
    cin >> button;
    switch (button)
    {
    case 'a':
        cout << "Hello" << endl;
        break;
    case 'b':
        cout << "Namaste" << endl;
        break;
    case 'c':
        cout << "Bonjour" << endl;
        break;
    default:
        cout << "I don't know any other language :-(";
        break;
    }
    return 0;
}

// Nested switch statements
#include <iostream>
using namespace std;
int main()
{
    char a = '1';
    int b = 1;
    switch (a)
    {
    case '1':
        cout << "Hello" << endl;
        switch (b)
        {
        case 1:
            cout << "Goodbye" << endl;
            break;
        }
    case '2':
        cout << "!!!!"; // This statement is executed because there was no break statement in the above case
        break;
    }
    return 0;
}