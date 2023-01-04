#include <iostream>
using namespace std;

void fact(int i, int ans)
{
    if (i < 1)
    {
        cout << ans;
        return;
    }
    fact(i - 1, ans * i);
}

int main()
{
    int n;
    cin >> n;
    fact(n, 1);
    return 0;
}