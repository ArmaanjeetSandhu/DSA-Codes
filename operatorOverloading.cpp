#include <iostream>
#include <string>
using namespace std;
struct channel
{
    string name;
    int count;
    channel(string abc, int a)
    {
        name = abc;
        count = a;
    }
};
ostream& operator << (ostream &foo, channel &bar)
{
    foo << "Name of Channel: " << bar.name << endl;
    foo << "Count: " << bar.count << endl;
    return foo;
}
int main() {
    channel aria("ChannelName", 216);
    cout << aria; // Since the '<<' operator would not have worked on the user-defined data type 'channel', we had to create an operator function, which overloads/redefines the '<<' operator for 'channel'
    operator << (cout, aria); // yields the same output
    return 0;
}