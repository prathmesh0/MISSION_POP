#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int, string> c;
    c.insert({1, "ram"});
    c.insert({2, "siya"});
    c.insert({3, "shiv"});
    c.insert({4, "parvati"});
    cout << "Elemnets present in the multimap: " << endl;
    cout << "Key\tValue" << endl;
    for (auto it = c.begin(); it != c.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }
    cout << endl;
    c.insert({4, "mahadev"});
    for (auto it = c.begin(); it != c.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }
    cout << endl;

    int n = 2;
    if (c.find(2) != c.end())
    {
        cout << n << " key is present" << endl;
    }

    c.erase(c.begin());
    for (auto it = c.begin(); it != c.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    c.clear();
    if (c.empty())
    {
        cout << "MultiMap is empty" << endl;
    }
    return 0;
}