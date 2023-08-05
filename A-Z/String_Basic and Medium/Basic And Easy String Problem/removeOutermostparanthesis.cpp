#include <iostream>
using namespace std;

// using count variable
string removeOuterParentheses(string s)
{
    int count = 0;
    string ans = "";
    for (char it : s)
    {
        if (it == '(')
        {
            if (count > 0)
            {
                ans += it;
            }
            count++;
        }
        if (it == ')')
        {
            count--;
            if (count > 0)
            {
                ans += it;
            }
        }
    }
    return ans;
}

// using stack
string removeOuterParentheses(string s)
{
    stack<char> st;
    string ans = "";

    for (auto it : s)
    {
        if (it == '(')
        {
            if (!st.empty())
            {
                ans += it;
            }
            st.push(it);
        }
        else if (it == ')')
        {
            st.pop();
            if (!st.empty())
            {
                ans += it;
            }
        }
    }
    return ans;
}

int main()
{
    string S = "(()())(())()";
    cout << removeOuterParentheses(S) << endl;
    return 0;
}