#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// map store all key in sorted ordered
// time complexity storing and fetching in map takes log(n)
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // pre-fetch
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // for (auto it : mpp)
    // {
    //     cout << it.first << "=>" << it.second << endl;
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}