#include <iostream>
#include <vector>
using namespace std;

// brute force
//  int findKRotation(vector<int> &arr)
//  {
//      // Write your code here.
//      int n = arr.size();
//      int ans = 0;
//      for (int i = 1; i < n; i++)
//      {
//          if (arr[i] < arr[i - 1])
//          {
//              ans = i;
//              break;
//          }
//      }
//      return ans;
//  }

// Optimal approach
int findKRotation(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        // left half is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }

        // right half is sorted
        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << ans << endl;
    return 0;
}