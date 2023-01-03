#include <iostream>
using namespace std;

void Print_name(int i, int n)
{
    if (i > n)
        return;
    cout << "POP" << endl;
    Print_name(i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    Print_name(1, n);
    return 0;
}