//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function returns the second
    // largest elements
    // approach 2
    int print2largest(int arr[], int n)
    {

        int largest = INT_MIN;
        int second_large = INT_MIN;
        // zero or one no. of element
        if (n == 0 || n == 1)
            return -1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > largest)
                largest = arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (second_large < arr[i] && arr[i] != largest)
            {
                second_large = arr[i];
            }
        }
        // same elements are in the array
        if (second_large == INT_MIN)
            return -1;
        else
            return second_large;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

/*
// brute - force
int Second_Largest(int arr[], int n)
{
    // edge case
    if (n == 0 || n == 1)
        return -1;
    sort(arr, arr + n);
    int ans = arr[n - 2];
    return ans;
}

int main()
{
    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = Second_Largest(arr, n);
    cout << "second largest element " << ans << endl;
    return 0;
}
*/