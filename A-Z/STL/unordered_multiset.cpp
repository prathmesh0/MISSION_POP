#include <iostream>
#include <unordered_set>
using namespace std;

void print(unordered_multiset<int> s)
{
    unordered_multiset<int> s1 = s;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    unordered_multiset<int> s;
    for (int i = 0; i <= 10; i++)
    {
        s.insert(i);
    }
    print(s);
    s.emplace(5);
    s.emplace(15);
    print(s);

    cout << "size of the unordered multiset " << s.size() << endl;
    s.erase(s.begin());
    print(s);
    s.clear();
    if (s.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "not empty" << endl;
    }
    return 0;
}