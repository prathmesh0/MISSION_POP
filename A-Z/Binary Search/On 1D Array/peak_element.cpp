#include <iostream>
using namespace std;

int peakEleBruteForce(int arr[], int n)
{
    if (arr[0] > arr[1])
        return arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }
    return arr[n - 1];
}
// optimal approach leetcode
class Solution
{
public:
    int findPeakElement(vector<int> &v)
    {
        int n = v.size() - 1;

        if (v.size() == 1)
            return 0;
        if (v[0] > v[1])
            return 0;
        if (v[n] > v[n - 1])
            return n;

        int low = 1, high = v.size() - 2, ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (v[mid - 1] < v[mid] && v[mid] > v[mid + 1])
            {
                ans = mid;
                break;
            }
            if (v[mid - 1] > v[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int arr[] = {3, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Peak Element is " << peakEleBruteForce(arr, n);
    return 0;
}