#include <bits/stdc++.h>
using namespace std;

void helper(int n, int ob, int cb, vector<string> &ans, string s)
{
    // BC
    if (ob == n && cb == n)
    {
        ans.push_back(s);
        return;
    }
    if (ob < n)
    {
        helper(n, ob + 1, cb, ans, s + '(');
    }
    if (cb < ob)
    {
        helper(n, ob, cb + 1, ans, s + ')');
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s = "";
    int ob = 0;
    int cb = 0;
    helper(n, ob, cb, ans, s);
    return ans;
}

int main()
{
    vector<string> v;
    int n = 3;
    v = generateParenthesis(n);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

 