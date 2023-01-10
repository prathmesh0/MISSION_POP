
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // optimal solution
    int largest(vector<int> &arr, int n)
    {
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }

    // brute-force
    int large(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        int ans = arr[arr.size() - 1];
        return (ans);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.large(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends