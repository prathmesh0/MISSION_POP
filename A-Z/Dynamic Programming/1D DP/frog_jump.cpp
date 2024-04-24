#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Memoization
// int helper(int ind, vector<int> &heights, vector<int> &dp)
// {
//     if (ind == 0)
//         return 0;
//     if (dp[ind] != -1)
//         return dp[ind];

//     int jumpOne = helper(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);

//     int jumpTwo = INT_MAX;
//     if (ind > 1)
//     {
//         jumpTwo = helper(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
//     }

//     return dp[ind] = min(jumpOne, jumpTwo);
// }

// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n + 1, -1);
//     return helper(n - 1, heights, dp);
// }

// // Tabulation
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n, -1);

//     dp[0] = 0;

//     for (int i = 1; i < n; i++)
//     {
//         int jumpOne = dp[i - 1] + abs(heights[i] - heights[i - 1]);

//         int jumpTwo = INT_MAX;
//         if (i > 1)
//             jumpTwo = dp[i - 2] + abs(heights[i] - heights[i - 2]);

//         dp[i] = min(jumpOne, jumpTwo);
//     }
//     return dp[n - 1];
// }

//Space Optimization
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 =0;

    for(int i = 1; i<n; i++){
        int jumpOne = prev1 + abs(heights[i] - heights[i-1]);
        int jumpTwo = INT_MAX;
        if(i>1){
             jumpTwo= prev2 + abs(heights[i] - heights[i-2]);
        }
        int curr_i = min(jumpTwo,jumpOne);
        prev2 = prev1;
        prev1 = curr_i;
    }
    return prev1;
}
vector<int> input(int &n)
{
    // Input the value of n
    cout << "Enter the value of n: ";
    cin >> n;

    // Input the heights
    vector<int> heights(n);
    cout << "Enter the heights: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    return heights;
}

int main()
{
    int n;
    vector<int> heights = input(n);

    // Call frogJump function and display the result
    int result = frogJump(n, heights);
    cout << "Minimum energy required: " << result << endl;

    return 0;
}
