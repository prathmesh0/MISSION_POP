#include <iostream>
using namespace std;
double power(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (x == 0)
        return 0;
    return x * power(x, n - 1);
}

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    else if (n % 2 == 0)
    {
        double ans = myPow(x, n / 2);
        return ans * ans;
    }
    else
    {
        return x * myPow(x, n - 1);
    }
}

int main()
{
    double x = 3.0;
    int n = 5;
    // cout << power(x, n);
    cout << myPow(x, n);
    return 0;
}