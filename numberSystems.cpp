#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int unsignedBinary(int n)
{
    float ans = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans += bit * pow(10, i++); // formula for forming a number in the reverse order of its digits, e.g., 321 from 1-->2-->3
        // ans = (ans * 10) + digit; for forming a number in the same order of its digits, e.g., 123 from 1-->2-->3
        n = n >> 1;
    }
    return ans;
}
int onesComplement(int n)
{
    int temp = unsignedBinary(n);
    float ans = 0;
    int i = 0;
    while (temp != 0)
    {
        int bit = temp ^ 1;
        ans += bit * pow(10, i++); // formula for forming a number in the reverse order of its digits
        temp = temp >> 1;
    }
    return temp;
}
int twosComplement(int n)
{
    return (onesComplement(n) + 0b1);
}
int signedBinary(int n)
{
    n *= -1;
    int temp = unsignedBinary(n);
    int bit = temp & 1;
    temp = 0;
}
int binaryToDecimal(int n)
{
    int i = 0, ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
            ans += pow(2, i);
        n /= 10;
        i++;
    }
    return ans;
}

vector<int> alsoUnsignedBinary(int n)
{
    vector<int> ans;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans.push_back(bit);
        n = n >> 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> alsoOnesComplement(int n)
{
    vector<int> arr = alsoUnsignedBinary(n);
    for (auto &i : arr)
    {
        if (i == 0)
            i = 1;
        else
            i = 0;
    }
    return arr;
}
vector<int> alsoTwosComplement(int n)
{
    vector<int> arr = alsoOnesComplement(n);
    int carry = 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int sum = arr[i] + carry;
        arr[i] = sum % 2;
        carry = sum / 2;
    }
    return arr;
}
vector<int> alsoSignedBinary(int n)
{
    if (n < 0)
    {
        n *= -1;
        return alsoTwosComplement(n);
    }
    else
        return alsoUnsignedBinary(n);
}
int alsoBinaryToDecimal(vector<int> arr)
{
    int ans = 0, j = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
        ans += arr[i] * pow(2, j++);
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "The binary value of " << n << " is " << unsignedBinary(n) << endl;
    cout << signedBinary(-7);
    return 0;
}