// A destructor is a member function that is automatically invoked whenever an object is destroyed. Destructors never take  arguments and do not return any value
#include <iostream>
using namespace std;
int count = 0;
class num
{
public:
    num() // constructor
    {
        cout << "Constructor called for object #" << ++count << endl;
    }
    ~num() // destructor
    {
        cout << "Destructor called for object #" << count-- << endl;
    }
};
int main()
{
    cout << "Creating first object n1..." << endl;
    num n1;
    // objects created within curly brackets are destroyed once the block is exited
    {
        cout << "Entering this block..." << endl;
        cout << "Creating two more objects..." << endl;
        num n2, n3;
        cout << "Exiting this block..." << endl;
    }
    cout << "Ending program..." << endl;
    return 0;
}
