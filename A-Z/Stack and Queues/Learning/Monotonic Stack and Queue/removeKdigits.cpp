#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k >= num.size())
        {
            return "0";
        }
        stack<char> st;
        for (int i = 0; i < num.length(); i++)
        {
            if (st.empty())
            {
                st.push(num[i]);
            }
            else
            {
                while (!st.empty() && st.top() > num[i] && k > 0)
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        // If 'k' is still remaining
        while (k > 0)
        {
            st.pop();
            k--;
        }
        if (st.empty())
        {
            return "0";
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (ans[i] == '0')
        {
            i++;
        }
        return (ans.substr(i) == "") ? "0" : ans.substr(i);
    }
};

// Input function to take inputs for 'num' and 'k' from the user
void takeInput()
{
    Solution sol;
    string num;
    int k;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the number of digits to remove (k): ";
    cin >> k;

    string result = sol.removeKdigits(num, k);
    cout << "Smallest possible number after removing " << k << " digits: " << result << endl;
}

int main()
{
    takeInput();
    return 0;
}
