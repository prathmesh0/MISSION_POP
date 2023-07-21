#include <iostream>
#include <vector>
using namespace std;

// Brute force
// int findMin(vector<int> &arr)
// {
//     int mini = INT_MAX;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] < mini)
//         {
//             mini = arr[i];
//         }
//     }
//     return mini;
// }

// optimal approach
// int findMin(vector<int> &num)
// {
//     int n = num.size();
//     int low = 0;
//     int high = n - 1;
//     int ans = INT_MAX;
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         // left part is sorted
//         if (num[low] <= num[mid])
//         {
//             ans = min(ans, num[low]);
//             low = mid + 1;
//         }
//         else
//         {
//             ans = min(ans, num[mid]);
//             high = mid - 1;
//         }
//     }
//     return ans;
// }

// more optimal
int findMin(vector<int> &num)
{
    int n = num.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (num[low] <= num[high])
        {
            ans = min(ans, num[low]);
            break;
        }
        // left part is sorted
        if (num[low] <= num[mid])
        {
            ans = min(ans, num[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, num[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}