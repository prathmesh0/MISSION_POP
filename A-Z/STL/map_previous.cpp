#include <iostream>
#include <map>
using namespace std;

int main()
{
    // Map
    //--> store element in mapped fassion
    //--> maps stores only unique keys

    map<string, int> mpp;
    mpp["raj"] = 12;
    mpp["pop"] = 19;
    mpp["pooja"] = 120;
    mpp["siya"] = 123;
    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
    cout << endl;
    mpp.emplace("diggu", 34);
    mpp.emplace("pooja", 45);
    mpp.emplace("uday", 19);

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;

    cout << "size of map = " << mpp.size() << endl;
    cout << "maximum size of map = " << mpp.max_size() << endl;
    cout << "empty or not ? " << mpp.empty() << endl;

    cout << endl;
    cout << endl;
    mpp.erase("raj");
    mpp.erase(mpp.begin());

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    mpp.clear();
    // another way of printing

    for (auto itr = mpp.begin(); itr != mpp.end(); itr++)
    {

        cout << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;

    return 0;
}