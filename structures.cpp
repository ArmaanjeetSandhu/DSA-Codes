/*
Each member of a structure has its own location, each of which is the size of the structure's largest data member. On the other hand, union members share a single memory location, which is the size of its largest data member.
*/
// Structures
#include <iostream>
using namespace std;
struct Student
{
    int id;
    float marks;
    char first_letter_in_name;
};
int main()
{
    struct Student Jack, Jill = Jack, John; // Jill's data will be the exact same as Jack's
    Jack.id = 347;                          // The . is known as the dot or member access operator
    Jack.marks = 75.5;
    Jack.first_letter_in_name = 'J';
    /*
    Alternatively, Jack = {347, 75.5, 'J'}
    */
    cout << "Jack's ID is " << Jack.id << "." << endl;
    return 0;
}
// Array of Structures
#include <iostream>
using namespace std;
struct marks
{
    int eng, math, chem, phy, total;
};
int main()
{
    struct marks student[3] = {{20, 30, 40, 50, 0}, {30, 40, 50, 60, 0}, {40, 50, 60, 70, 0}};
    struct marks total;
    for (int i = 0; i <= 2; i++)
    {
        student[i].total = student[i].eng + student[i].math + student[i].chem + student[i].phy; // calculating total for each student
        // calculating total for each subject
        total.eng += student[i].eng;
        total.math += student[i].math;
        total.chem += student[i].chem;
        total.phy += student[i].phy;
        total.total += student[i].total;
    }
    for (int i = 0; i <= 2; i++)
    {
        cout << student[i].total << endl;
    }
    cout << total.eng << "\n"
         << total.math << "\n"
         << total.chem << "\n"
         << total.phy << "\n"
         << total.total << endl;
    return 0;
}
// Passing a structure as an argument to a function, and calling by value
#include <iostream>
using namespace std;
struct stores
{
    char name[20];
    float price;
    int quantity;
};
struct stores update(struct stores product, float p, int q)
{
    product.price += p;
    product.quantity += q;
    return product;
}
float mul(struct stores stock)
{
    return (stock.price * stock.quantity);
}
int main()
{
    float p_increment, value;
    int q_increment;
    struct stores item = {"XYZ", 25.75, 12};
    cin >> p_increment >> q_increment;
    item = update(item, p_increment, q_increment);
    cout << "Price: " << item.price << endl;
    cout << "Quantity: " << item.quantity << endl;
    value = mul(item);
    cout << "Value of the item = " << value << endl;
    return 0;
}
// Passing a structure as an argument to a function, and calling by reference
#include <iostream>
using namespace std;
struct marks
{
    int m1;
    int m2;
    int m3;
    int total;
    int average;
};
int tot(struct marks *max)
{
    max->total = max->m1 + max->m2 + max->m3; // -> is known as the arrow operator
    max->average = max->total / 3;
    return max->average;
}
int main()
{
    struct marks max = {10, 20, 30, 0, 0};
    int x = tot(&max);
    cout << x;
    return 0;
}
// Sample Code
#include <iostream>
using namespace std;
int total(int m[], int n)
{
    int i = 2, tot = 0;
    for (i = 0; i < n; i++)
        tot += m[i];
    return tot;
};
struct student
{
    char name[20];
    int rollno;
    int marks[3];
};
int main()
{
    struct student s1 = {"xyz", 530, 80, 75, 85};
    int t;
    t = total(s1.marks, 3);
    cout << "Total: \t" << t << endl;
    return 0;
}