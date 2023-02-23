// iterative approach

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string res;
        int count = 0;
        for (char it : S)
        {
            if (it == '(')
            {
                if (count++)
                {
                    res += '(';
                }
            }
            else
            {
                if (--count)
                {
                    res += ')';
                }
            }
        }
        return res;
    }
};