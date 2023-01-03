#include <iostream>
#include <set>
using namespace std;

int main()
{
    // multi_set
    //-->it store multiple elements having same values
    //-->store in sorted fassion
    multiset<int> ms;
    ms.insert(12);
    ms.insert(10);
    ms.insert(16);
    ms.insert(16);
    ms.insert(10);

    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "size = " << ms.size() << endl;
    cout << " maximum_size = " << ms.max_size() << endl;
    cout << "count of 10 =" << ms.count(10) << endl;
    ms.clear();

    if (ms.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "not empty" << endl;
    }

    ms.emplace(999000);
    ms.emplace(9990);
    ms.emplace(99900);
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}