#include <bits/stdc++.h>
using namespace std;

void helper(int ind, string digits, string mapping[], string output, vector<string> &ans)
{
    // BC
    if (ind == digits.size())
    {
        ans.push_back(output);
        return;
    }
    int number = digits[ind] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.size(); i++)
    {
        output.push_back(value[i]);
        helper(ind + 1, digits, mapping, output, ans);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
    {
        return ans;
    }
    string output = "";
    int ind = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    helper(ind, digits, mapping, output, ans);
    return ans;
}

int main()
{
    string digits;
    cout << "Enter a string of digits (e.g., '23' or '789'): ";
    cin >> digits;

    vector<string> combinations = letterCombinations(digits);

    if (combinations.empty())
    {
        cout << "No letter combinations found for the input digits." << endl;
    }
    else
    {
        cout << "Letter combinations for the input digits '" << digits << "':" << endl;
        for (const string &combination : combinations)
        {
            cout << combination << endl;
        }
    }

    return 0;
}
