//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printTriangle(int n)
    {

        int space = 2 * n - 2;

        for (int i = 1; i <= (2 * n - 1); i++)
        {

            int star = i;

            if (i > n)
                star = 2 * n - i;

            // star
            for (int j = 1; j <= star; j++)
            {
                cout << "*";
            }

            // space
            for (int j = 1; j <= space; j++)
            {
                cout << " ";
            }

            // star
            for (int j = 1; j <= star; j++)
            {
                cout << "*";
            }
            cout << endl;
            if (i < n)
                space -= 2;
            else
                space += 2;
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