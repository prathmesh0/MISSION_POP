#include <iostream>
using namespace std;

int main()
{
    // initialization
    pair<int, int> roll(12, 45);
    cout << roll.first << " " << roll.second << endl;
    // copy pair
    pair<int, int> no(roll);
    cout << no.first << " " << no.second << endl;

    // swap pairs
    pair<int, int> h1(39, 89);
    roll.swap(h1);
    cout << roll.first << " " << roll.second << endl;
    return 0;
}