#include <bits/stdc++.h>
using namespace std;

int subsequence(vector<int> &v, int sum, vector<int> &ds, int ind, int s, int n)
{
    // BC
    if (ind == n)
    {
        if (sum == s)
        {
            return 1;
        }
        return 0;
    }

    // Include
    ds.push_back(v[ind]);
    s += v[ind];
    int l = subsequence(v, sum, ds, ind + 1, s, n);

    // Exclude
    s -= v[ind];
    ds.pop_back();
    int r = subsequence(v, sum, ds, ind + 1, s, n);

    return (l + r);
}

int main()
{
    vector<int> v = {1, 2, 1};
    int sum = 2;
    int n = 3;
    vector<int> ds;
    int ans = subsequence(v, sum, ds, 0, 0, n);
    cout << ans << endl;
    return 0;
}