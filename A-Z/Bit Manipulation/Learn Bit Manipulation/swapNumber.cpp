#include <iostream>
using namespace std;

void swapNumber(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a = 5, b = 10;
    cout << a << " " << b << endl;
    ;
    swapNumber(a, b);
    cout << a << " " << b;
    return 0;
}