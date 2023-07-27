#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int k, int dist)
{
    int n = stalls.size();
    int cntCow = 1;
    int last = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCow++;
            last = stalls[i];
        }
        if (cntCow >= k)
            return true;
    }
    return false;
}

// Brute force approach
//  int aggressiveCows(vector<int> &stalls, int k)
//  {
//      int n = stalls.size();
//      sort(stalls.begin(), stalls.end());
//      int limit = stalls[n - 1] - stalls[0];

//     for (int i = 1; i <= limit; i++)
//     {
//         if (canWePlace(stalls, k, i) == false)
//         {
//             return (i - 1);
//         }
//     }
//     return limit;
// }
// Optimal  approach
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canWePlace(stalls, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}