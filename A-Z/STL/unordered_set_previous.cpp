#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // unordered set
    //->store unique element in any order
    //->TC=O(1) & O(n) in worst cases

    unordered_set<int> us;
    us.insert(12);
    us.insert(17);
    us.insert(10);

    for (auto i : us)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto it = us.begin(); it != us.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "size= " << us.size();
    cout << endl;
    cout << " maximum size= " << us.max_size();
    cout << endl;
    if (us.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << " Not Empty" << endl;
    }
    us.emplace(67);
    us.emplace(90);
    for (auto it : us)
    {
        cout << it << " ";
    }
    cout << endl;

    // erase function
    us.erase(67);
    us.erase(us.begin());
    for (auto it : us)
    {
        cout << it << " ";
    }
    cout << endl;

    us.erase(us.begin(), us.end());

    cout << endl;

    return 0;
}