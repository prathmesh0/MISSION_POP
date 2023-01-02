#include <iostream>
using namespace std;
// pass by value

void func(int &x, int &y)
{
    x = x + 10;
    y = y + 20;
    cout << "values of x and y in function" << endl;
    cout << x << " " << y << endl;
}

int main()
{
    int x = 10, y = 20;
    func(x, y);
    cout << "values of x and y in main function" << endl;
    cout << x << " " << y << endl;
    return 0;
}