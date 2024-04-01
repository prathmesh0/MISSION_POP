#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (count > 0 && s[i] == ' ')
                break;
            if (s[i] != ' ')
                count++;
        }
        return count;
    }
};

string getInput()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    return s;
}

int main()
{
    Solution solution;
    string input = getInput();
    int result = solution.lengthOfLastWord(input);
    cout << "Length of last word: " << result << endl;
    return 0;
}
