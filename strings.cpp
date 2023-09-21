#include <iostream>
#include <vector>
using namespace std;
string toLowercase(string &s)
{
    string result;
    for (char i : s)
    {
        if (65 <= i && i <= 90)
            i += 32;
        result += i;
    }
    return result;
}
void func(vector<char> arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (97 <= arr[i] && arr[i] <= 122)
            count++;
    }
    vector<char> d(count);
    int i = 0, j = 0;
    while (i < arr.size() && j < count)
    {
        if (97 <= arr[i] && arr[i] <= 122)
            d[j++] = arr[i];
        i++;
    }
    for (char c : d)
        cout << c;
}
bool isPalindrome(string s)
{
    int size = s.size();
    for (int i = 0; i < size / 2; i++)
    {
        if (s[i] != s[size - i - 1])
            return false;
    }
    return true;
}
bool isPalindromeRecursive(string s, int i, int j)
{
    if (i > j)
        return true;
    if (s[i] != s[j])
        return false;
    else
        return isPalindromeRecursive(s, ++i, --j);
}
string bubbleSort(string &str)
{
    int n = str.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    return str;
}
bool areAnagrams(string a, string b)
{
    if (a.size() == b.size())
    {
        a = bubbleSort(a);
        b = bubbleSort(b);
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                return 0;
        }
        return 1;
    }
    else
        return 0;
}
void reverseRecursive(string &s, int i, int j)
{
    if (i > j)
        return;
    swap(s[i++], s[j--]);
    reverseRecursive(s, i, j);
}
int main()
{
    char c[16];
    cout << "Enter a string with a whitespace in it: ";
    cin >> c;
    cout << c; // only the portion before the whitespace is printed (because cin does not accept input after tab, space or enter)

    char d[16];
    cout << "Enter a string with a whitespace in it: ";
    cin.getline(d, sizeof(d));
    cout << d; // entire input gets printed

    char e[16], delimiter = '@';
    cout << "Enter a string: ";
    cin.getline(e, sizeof(e), delimiter);
    cout << e; // only the portion before the delimiter is printed

    // Unlike a character array, a character vector does not implicitly have a null character ('\0') at the end because it's not treated as a string.
    string s = "Fantastic";
    vector<char> word(s.begin(), s.end()); // initializing a character vector using a string literal
    return 0;
}