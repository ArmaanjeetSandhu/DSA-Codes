// check if n is prime or not
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "not prime";
            break; // if this statement were 'continue', the output "not prime" would be printed for each value of i for which n%i==0
        }
    }
    cout << "prime";
    return 0;
}
// print all prime numbers between a and b
#include <iostream>
using namespace std;
int main()
{
    int n, i, a, b;
    cin >> a >> b;
    for (int n = a + 1; n < b; n++)
    {
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
                break;
        }
        if (i == n)
            cout << n << endl;
    }
    return 0;
}