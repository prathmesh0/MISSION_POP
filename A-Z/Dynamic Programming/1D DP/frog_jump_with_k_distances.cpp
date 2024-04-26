
#include <bits/stdc++.h>
using namespace std;

// int solveUtil(int ind, vector<int> &height, vector<int> &dp, int k)
// {
//     // Base case: If we are at the beginning (index 0), no cost is needed.
//     if (ind == 0)
//         return 0;

//     // If the result for this index has been previously calculated, return it.
//     if (dp[ind] != -1)
//         return dp[ind];

//     int mmSteps = INT_MAX;

//     // Loop to try all possible jumps from '1' to 'k'
//     for (int j = 1; j <= k; j++)
//     {
//         // Ensure that we do not jump beyond the beginning of the array
//         if (ind - j >= 0)
//         {
//             // Calculate the cost for this jump and update mmSteps with the minimum cost
//             int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
//             mmSteps = min(jump, mmSteps);
//         }
//     }

//     // Store the minimum cost for this index in the dp array and return it.
//     return dp[ind] = mmSteps;
// }

// // Function to find the minimum cost to reach the end of the array
// int solve(int n, vector<int> &height, int k)
// {
//     vector<int> dp(n, -1);                  // Initialize a memoization array to store calculated results
//     return solveUtil(n - 1, height, dp, k); // Start the recursion from the last index
// }

int helper(int n, int k, vector<int> &height, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mmSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1];
}

int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);
    return helper(n, k, height, dp);
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1);
    cout << solve(n, height, k) << endl;
    return 0;
}
