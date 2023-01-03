#include <iostream>
using namespace std;

int sumOfn(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumOfn(n - 1);
}

int main()
{
    int n;
    cin >> n;
    int ans = sumOfn(n);
    cout << "sum = " << ans << endl;
    return 0;
}