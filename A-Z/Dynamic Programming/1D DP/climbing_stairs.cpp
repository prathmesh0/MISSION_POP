#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Solution 1: Iterative approach using two variables
    int climbStairs1(int n)
    {
        int prev1 = 1;
        int prev2 = 1;

        for (int i = 2; i <= n; i++)
        {
            int curr_i = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr_i;
        }
        return prev1;
    }

    // Solution 2: Recursive approach with memoization
    int f(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = f(n - 1, dp) + f(n - 2, dp);
    }

    int climbStairs2(int n)
    {
        vector<int> dp(n + 1, -1);
        int ans = f(n, dp);
        return ans;
    }

    // Solution 3: Iterative approach with dynamic programming
    int climbStairs3(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

vector<int> input(int n)
{
    // Create a vector of size n+1 initialized with -1
    return vector<int>(n + 1, -1);
}

int main()
{
    // Test all three solutions
    Solution s;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Solution 1: " << s.climbStairs1(n) << endl;
    cout << "Solution 2: " << s.climbStairs2(n) << endl;
    cout << "Solution 3: " << s.climbStairs3(n) << endl;

    return 0;
}
