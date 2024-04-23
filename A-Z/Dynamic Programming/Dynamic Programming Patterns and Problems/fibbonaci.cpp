#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp)
{
    // BC
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    // memoization
    int n;
    cin >> n;
    // vector<int> v(n + 1, -1);
    // cout << fib(n, v) << endl;

    // tabulation

    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

    // Space Optimization
    int prev1 = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr_i = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr_i;
    }
    cout << prev1 << endl;

    return 0;
}