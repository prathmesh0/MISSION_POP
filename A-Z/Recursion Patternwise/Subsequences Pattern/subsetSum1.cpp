#include <bits/stdc++.h>
using namespace std;

void helper(int ind, vector<int> &ans, vector<int> &arr, int n, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }

    // Pick up
    helper(ind + 1, ans, arr, n, sum + arr[ind]);
    // Not pick
    helper(ind + 1, ans, arr, n, sum);
}
vector<int> subsetSums(vector<int> &arr, int n)
{
    vector<int> ans;
    helper(0, ans, arr, n, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr{3, 1, 2};

    vector<int> ans = subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}