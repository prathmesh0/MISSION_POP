//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printTriangle(int n)
    {
        // symetrical pattern
        int space = 0;
        for (int i = 0; i < n; i++)
        {

            // stars
            for (int j = 1; j <= (n - i); j++)
            {
                cout << "*";
            }

            // space
            for (int j = 0; j < space; j++)
            {
                cout << " ";
            }

            // stars
            for (int j = 1; j <= (n - i); j++)
            {
                cout << "*";
            }

            space += 2;
            cout << endl;
        }

        space = 2 * n - 2;
        for (int i = 1; i <= n; i++)
        {
            // stars
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }

            // space
            for (int j = 0; j < space; j++)
            {
                cout << " ";
            }

            // stars
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }

            space -= 2;
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends