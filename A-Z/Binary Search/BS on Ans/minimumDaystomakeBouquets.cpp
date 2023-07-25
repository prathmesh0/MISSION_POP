#include <iostream>
#include <vector>
using namespace std;

bool possible(vector<int> &arr, int k, int m, int day)
{
    int n = arr.size();
    int count = 0;
    int noOfB = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            count++;
        }
        else
        {

            noOfB += (count / k);
            count = 0;
        }
    }
    noOfB += (count / k);
    return (noOfB >= m);
}

// Brute force approach
//  int flowerGarden(vector<int> &arr, int k, int m)
//  {
//      int n = arr.size();
//       long long val = m * 1ll * k * 1ll;
//      if (val > n)
//          return - 1;

//     int mini = INT_MAX, maxi = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(maxi, arr[i]);
//         mini = min(mini, arr[i]);
//     }

//     for (int i = mini; i < maxi; i++)
//     {
//         if (possible(arr, k, m, i))
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// Optimal Approach
int flowerGarden(vector<int> &arr, int k, int m)
{
    int n = arr.size();
    long long val = m * 1ll * k * 1ll;
    if (val > n)
        return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }

    int low = mini, high = maxi;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(arr, k, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = flowerGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}