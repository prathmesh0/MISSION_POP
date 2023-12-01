#include <iostream>
#include <stack>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return -1;
}
string infixToPostfix(string exp)
{
    stack<char> st;
    string res;
    for (int i = 0; i < exp.size(); i++)
    {
        // check for alphabet and number
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            res += exp[i];
        }
        else
        {
            if (exp[i] == '(')
            {
                st.push('(');
            }
            else if (exp[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            // if  operand is scanned
            else
            {
                while (!st.empty() && prec(exp[i]) <= prec(st.top()))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    string ans = infixToPostfix(exp);
    cout << "Postfix expression: " << ans << endl;

    return 0;
}