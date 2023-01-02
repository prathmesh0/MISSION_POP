#include <iostream>
using namespace std;

void swapNumber(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}
int findSum(int x, int y)
{
    return (x + y);
}

int main()
{
    int x, y;
    cin >> x >> y;
    int sum = findSum(x, y);
    cout << x << " + " << y << " = " << sum << endl;
    swapNumber(x, y);
    cout << "Number after swap" << endl;
    cout << x <<" "<< y << endl;
    return 0;
}