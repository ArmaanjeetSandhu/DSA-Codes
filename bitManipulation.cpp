#include <iostream>
#include <cmath>
using namespace std;
int setBitsCount1(int n)
{
    int count = 0;
    while (n != 0)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int setBitsCount2(int n)
// Brian Kernighan's Algorithm (based on the fact that upon subtracting 1 from an integer, the rightmost set bit becomes unset and all bits to its right are flipped)
{
    int count = 0;
    while (n != 0)
    {
        n &= n - 1;
        count++;
    }
    return count;
}
// ALITER: __builtin_popcount(int n) also returns the number of set bits in n
void oddOrEven(int n)
{
    if (n & 1) // The LSB is set if the number is odd
        cout << "Odd" << endl;
    else
        cout << "Odd" << endl;
}
void swap(int a, int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}
int ithBit(int a, int i)
{
    int mask = 1 << i;
    if ((a & mask) == 0)
        return 0;
    else
        return 1;
}
int set_ith_bit(int a, int i)
{
    int mask = 1 << i;
    return (a | mask);
}
int clear_ith_bit(int a, int i)
{
    return (a & ~(1 << i));
}
int main()
{
    // AND &    OR |    XOR ^   LEFT SHIFT <<   RIGHT SHIFT >>
    int x = 3;                // Since x is int, sizeof(x) = 4 bytes = 32 bits
    cout << (3 << 2) << endl; // 3 in 32-bit binary format is shifted to the left by 2 spaces, and the integer value of the result is printed
    // Left shift yields --> left operand * 2^(right operand)
    // Right shift yields --> left operand / 2^(right operand)
    return 0;
}