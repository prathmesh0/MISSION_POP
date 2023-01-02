#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 5;
    // arithmetic operator
    //-->Binary
    cout << "The value of a+b = " << a + b << endl;
    cout << "The value of a-b = " << a - b << endl;
    cout << "The value of a/b = " << a / b << endl;
    cout << "The value of a*b = " << a * b << endl;
    cout << "The value of a%b = " << a % b << endl;
    //-->Unary
    // Increment (a) by (a+1) and then print
    cout << "pre-increment of a =" << ++a << endl;

    // First print (a) and then increment it by 1
    cout << "post-increment of a =" << a++ << endl;

    // same as above only decrement will be happens
    cout << "pre-decrement of b =" << --b << endl;
    cout << "post-decrement of b =" << b-- << endl;

    // Logical operator and relational opertor
    int c = 20, d = 30;
    if ((c < d) && (c != d))
    {
        cout << "logical &&" << endl;
    }

    if ((c < d) || (c == d))
    {
        cout << "logical ||" << endl;
    }

    if ((c != d))
    {
        cout << "logical !" << endl;
    }

    // bitwise operator
    int x = 12, y = 25;
    cout << "value of bitwise & operator = " << (12 & 25) << endl;
    cout << "value of bitwise | operator = " << (12 | 25) << endl;
    cout << "value of bitwise ^ operator = " << (12 ^ 25) << endl;
    cout << "value of bitwise not operator = " << ~(12) << endl;
    //--> left and right shift
    int r = 212;
    cout << "left shift = " << (r << 1) << endl;
    cout << "left shift = " << (r << 5) << endl;

    cout << "right shift = " << (r >> 2) << endl;
    cout << "right shift = " << (r >> 7) << endl;

    // asssignment operator
    //=, +=, -=,...
    x = 30;
    cout << "value of x  = " << x << endl;
    x += 5;
    cout << "value of x  = " << x << endl;
    x /= 5;
    cout << "value of x  = " << x << endl;

    // other operator
    // sizeof() , conditional(?), comma /  separator(,)
    return 0;
}