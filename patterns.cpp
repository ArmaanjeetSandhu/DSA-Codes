#include <iostream>
using namespace std;
int main()
{
    int rows, columns;
    cin >> rows >> columns;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= columns; j++)
            cout << columns - j + 1 << " ";
        cout << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int rows, columns, count = 1;
    cin >> rows >> columns;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 1; j < columns; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int rows;
    cin >> rows;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i - j + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int rows, columns, x = 1;
    cin >> rows >> columns;
    char count = 'A';
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            cout << count << " ";
            count++;
        }
        count = 'A' + x++;
        cout << endl;
    }
    return 0;
}