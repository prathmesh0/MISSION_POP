#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> mp;
    for (int i = 1; i <= 5; i++)
    {
        mp.insert({i, i * 10});
    }

    cout << "Element in the map: " << endl;
    cout << "Key\tValue" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    int n = 2;
    if (mp.find(2) != mp.end())
        cout << n << " element is present in the map" << endl;

    mp.erase(mp.begin());
    cout << "After deleting the first value in the map: " << endl;
    cout << "Key\tValue" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    cout << "size of the map = " << mp.size() << endl;
    return 0;
}