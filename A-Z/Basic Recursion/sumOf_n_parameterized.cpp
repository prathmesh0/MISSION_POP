#include <iostream>
using namespace std;
void sumOfn(int i, int sum)
{
    if (i < 1)
    {
        cout << "sum = " << sum << endl;
        return;
    }
    sumOfn(i - 1, sum + i);
}

int main()
{
    int n;
    cin >> n;
    sumOfn(n, 0);
    return 0;
}