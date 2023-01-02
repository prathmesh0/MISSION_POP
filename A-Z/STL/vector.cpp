#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // initialization
    vector<int> v;
    // inserting element
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
    }
    cout << "element in the vectors are :" << endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "front element in the vector " << v.front() << endl;
    cout << "last element in the vector " << v.back() << endl;
    cout << "size of the vector " << v.size() << endl;

    // removing an element
    v.pop_back();
    v.pop_back();
    cout << "after removing the element " << endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "inserting 15 at the beginning " << endl;
    v.insert(v.begin(), 15);
    cout << "the first element of the vector " << v[0] << endl;
    cout << "erasing the 3 rd element :" << endl;
    v.erase(v.begin() + 3);
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    if (v.empty())
    {
        cout << "vector is empty" << endl;
    }
    else
    {
        cout << "vector is not empty" << endl;
    }

    v.clear();
    cout << "size of the vector :" << v.size() << endl;

    return 0;
}