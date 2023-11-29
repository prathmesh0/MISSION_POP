#include <iostream>
#include <stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> st;
        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
            {
                st.push(it);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                char ch = st.top();
                st.pop();
                if ((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};

void testIsValid(const std::string &input)
{
    Solution solution;
    bool isValid = solution.isValid(input);
    std::cout << "Input: \"" << input << "\" -> Is Valid: " << (isValid ? "true" : "false") << std::endl;
}

int main()
{
    // Test cases
    testIsValid("()");     // Balanced parentheses
    testIsValid("()[]{}"); // Balanced parentheses and brackets
    testIsValid("(]");     // Unbalanced parentheses
    testIsValid("([)]");   // Unbalanced parentheses and brackets
    testIsValid("{[]}");   // Balanced braces and brackets
    testIsValid("{{{{");   // Unbalanced braces
    testIsValid("");       // Empty string (considered balanced)
    testIsValid("abc");    // No brackets or parentheses (considered balanced)

    return 0;
}
