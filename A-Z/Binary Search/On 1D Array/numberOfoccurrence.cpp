//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int first_Occurence(int arr[], int n, int target)
    {
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (target == arr[mid])
            {
                ans = mid;
                e = mid - 1;
            }
            else if (target > arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }

public:
    int last_Occurence(int arr[], int n, int target)
    {
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (target == arr[mid])
            {
                ans = mid;
                s = mid + 1;
            }
            else if (target > arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }

public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int nums[], int n, int target)
    {

        int firstOccur = first_Occurence(nums, n, target);
        int lastOccur = last_Occurence(nums, n, target);

        if (firstOccur == -1 && lastOccur == -1)
            return 0;
        else
            return ((lastOccur - firstOccur) + 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends