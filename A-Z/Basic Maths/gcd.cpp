#include <iostream>
using namespace std;

int gcd(int n1, int n2)
{
    int ans;
    for (int i = 1; i <= min(n1, n2); i++)
    {
        if ((n1 % i == 0) && (n2 % i == 0))
            ans = i;
    }
    return ans;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int ans = gcd(n1, n2);
    cout << "GCD of numbers = " << ans << endl;
    return 0;
}