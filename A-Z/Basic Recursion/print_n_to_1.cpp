#include <iostream>
using namespace std;

void Print(int i, int n)
{
    if (i < 1)
        return;
    cout << i << " ";
    Print(i - 1, n);
}

int main()
{
    int n;
    cin >> n;
    Print(n, n);
    return 0;
}