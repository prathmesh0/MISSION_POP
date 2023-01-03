#include <iostream>
#include <map>
using namespace std;

int main()
{
    // multimap
    //-->multiple element have same key
    //-->store all keys in sorted ordered
    multimap<int, int> tik;
    tik.emplace(12, 344);
    tik.emplace(13, 345);
    tik.emplace(1, 3);
    tik.emplace(62, 44);
    tik.emplace(62, 44);

    // printing the multimap
    for (auto it : tik)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;

    for (auto i = tik.begin(); i != tik.end(); i++)
    {
        cout << i->first << " " << i->second;
        cout << endl;
    }
    cout << endl;
    cout << endl;

    cout << "size of u_map = " << tik.size() << endl;
    cout << "maximum size of u_map = " << tik.max_size() << endl;
    cout << "empty or not ? " << tik.empty() << endl;
    cout << " count = " << tik.count(62) << endl;
    tik.erase(tik.begin(), tik.end());
    cout << endl;
    cout << endl;
    return 0;
}