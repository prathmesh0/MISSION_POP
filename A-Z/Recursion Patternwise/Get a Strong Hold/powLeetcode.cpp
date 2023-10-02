#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    // handle INT_MIN
    if (n == INT_MIN)
    {
        x *= x; // Multiply x by itself to make n even
        n = n / 2;
    }

    if (n < 0)
    {
        x = 1 / x;
        n = -(n);
    }
    double temp = myPow(x, n / 2);
    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return x * temp * temp;
    }
}

int main()
{
    double x;
    int n;

    std::cout << "Enter the base (x): ";
    std::cin >> x;

    std::cout << "Enter the exponent (n): ";
    std::cin >> n;

    double result = myPow(x, n);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
