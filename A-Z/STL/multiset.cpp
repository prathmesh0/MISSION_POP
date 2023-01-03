#include <iostream>
#include <set>
using namespace std;

void printMultiset(multiset<int> m)
{
    multiset<int> m1 = m;
    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    multiset<int> m;
    for (int i = 0; i < 11; i++)
    {
        m.insert(i);
    }
    printMultiset(m);
    m.emplace(123);
    m.emplace(13);
    m.emplace(3);
    printMultiset(m);

    // find
    int n = 10;
    if (m.find(10) != m.end())
    {
        cout << "element is present" << endl;
    }
    m.erase(m.begin());
    printMultiset(m);

    cout << "size of the multiset " << m.size() << endl;
    m.clear();
    if (m.empty())
    {
        cout << "Multiset is empty" << endl;
    }
    return 0;
}