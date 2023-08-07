#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    // grab the first word for compare
    for (int i = 0; i < strs[0].size(); i++)
    {
        // obtain all char of first word
        char ch = strs[0][i];
        bool flag = true;

        // traverse all remaining words except first
        for (int j = 1; j < strs.size(); j++)
        {
            // if current chaacter  not matches with character of all string

            if (strs[j].size() < i || ch != strs[j][i])
            {
                flag = false;
                break;
            }
        }
        // char not matches then break from loop
        if (flag == false)
        {
            break;
        }
        // if char match then add that char into ans string
        else
        {
            ans += ch;
        }
    }
    return ans;
}

int main()
{
    vector<string> st = {{"flower"},{"flow"}, {"floss"}};
    string ans = longestCommonPrefix(st);
    cout<<ans<<endl;
    return 0;
}