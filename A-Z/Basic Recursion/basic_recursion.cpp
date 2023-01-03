#include <iostream>
using namespace std;

// print the no.from 0 to 2
int cnt = 0;
void f()
{
    if (cnt == 3)
        return;
    cout << cnt << " ";
    cnt++;
    f();
}
int main()
{
    f();
    return 0;
}