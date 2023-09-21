#include <iostream>
#include <fstream>
#include <string> // for getline function
using namespace std;
int main()
{
    string s1 = "Look here!\n";
    string s2 = "This is a sample text document.\n";
    string s3 = "It contains no useful information.";
    ofstream out("file.txt"); // ALITER: ofstream out; out.open("file.txt");
    out << "[READ BELOW]\n" + s1 + s2 + s3;
    out.close();
    string st;
    ifstream in("file.txt"); // ALITER: ifstream in; in.open("file.txt");
    getline(in, st);         // for only the first line of the file
    cout << st << endl;
    while (in.eof() == 0)
    {
        getline(in, st);
        cout << st << endl;
    }
    in.close();
    return 0;
}