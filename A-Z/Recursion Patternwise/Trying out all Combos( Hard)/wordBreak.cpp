#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool helper(int i, std::string s, std::unordered_set<std::string> &st)
    {
        if (i == s.size())
        {
            return true;
        }
        string temp = "";
        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];
            if (st.find(temp) != st.end())
            {
                if (helper(j + 1, s, st))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        unordered_set<string> st;
        for (auto it : wordDict)
        {
            st.insert(it);
        }
        bool ans = helper(0, s, st);
        return ans;
    }
};

int main()
{
    Solution solution;
    std::string s;
    std::vector<std::string> wordDict;

    std::cout << "Enter the input string: ";
    std::cin >> s;

    std::cout << "Enter the size of the word dictionary: ";
    int dictSize;
    std::cin >> dictSize;

    std::cout << "Enter the words in the dictionary, one per line:" << std::endl;
    for (int i = 0; i < dictSize; i++)
    {
        std::string word;
        std::cin >> word;
        wordDict.push_back(word);
    }

    bool result = solution.wordBreak(s, wordDict);

    if (result)
    {
        std::cout << "The input string can be segmented using the provided word dictionary." << std::endl;
    }
    else
    {
        std::cout << "The input string cannot be segmented using the provided word dictionary." << std::endl;
    }

    return 0;
}
