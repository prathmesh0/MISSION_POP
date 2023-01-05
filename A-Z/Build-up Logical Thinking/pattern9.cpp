//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printDiamond(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // space
            for (int j = 0; j < (n - i - 1); j++)
            {
                cout << " ";
            }

            // star
            for (int j = 0; j < (2 * i + 1); j++)
            {
                cout << "*";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++)
        {
            // space
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }

            // star
            for (int j = 0; j < 2 * n - (2 * i + 1); j++)
            {
                cout << "*";
            }
            cout << endl;
        }
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

        Solution ob;
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends