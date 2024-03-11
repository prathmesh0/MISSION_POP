#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        string s1, s2;
        int map[26] = {0};

        for (auto it : order)
        {
            map[it - 'a']++;
        }

        for (auto it : s)
        {
            if (map[it - 'a'] == 0)
            {
                s2 += it;
            }
            else
            {
                map[it - 'a']++;
            }
        }

        for (auto it : order)
        {
            while (map[it - 'a'] > 1)
            {
                s1 += it;
                map[it - 'a']--;
            }
        }
        return (s1 + s2);
    }
};

pair<string, string> readInput()
{
    string order, s;
    cout << "Enter the order string: ";
    cin >> order;
    cout << "Enter the string s: ";
    cin >> s;
    return make_pair(order, s);
}

int main()
{
    Solution solution;
    auto input = readInput();
    string order = input.first;
    string s = input.second;
    cout << "Custom sorted string: " << solution.customSortString(order, s) << endl;
    return 0;
}
