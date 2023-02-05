#include <iostream>
#include <math.h>
using namespace std;
/*
//iterative approach
bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
*/
// mathematical approach thinking
bool isPrime(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    bool ans = isPrime(n);
    if (n != 1 && ans == true)
    {
        cout << "Given number is a prime number" << endl;
    }
    else
    {
        cout << "Given number is not prime number" << endl;
    }
    return 0;
}