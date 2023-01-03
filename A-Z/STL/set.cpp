#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    for (int i = 1; i <= 10; i++)
    {
        s.insert(i);
    }
    cout << "Element present in the set :" << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    s.emplace(4);
    s.emplace(14);
    cout << "Element present in the set :" << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    int n = 14;
    if (s.find(14) != s.end())
    {
        cout << n << " is present in the set" << endl;
    }
    // erase
    s.erase(s.begin());
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "size of the set " << s.size() << endl;
    s.clear();
    if (s.empty())
    {
        cout << "set is empty" << endl;
    }
    else
    {
        cout << "set is not empty" << endl;
    }
    return 0;
}