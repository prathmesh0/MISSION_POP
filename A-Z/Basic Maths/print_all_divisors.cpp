#include <iostream>
#include <math.h>
using namespace std;

// tc = O(n2)
/*void divisors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}
*/
void divisors(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
            {
                cout << (n / i) << " ";
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    divisors(n);
    return 0;
}