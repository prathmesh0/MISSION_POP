#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*bool isAnagram(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}
*/

bool isAnagram(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    int freq[26] = {0};

    for (int i = 0; i < s1.size(); i++)
    {
        freq[s1[i] - 'A']++;
    }

    for (int i = 0; i < s2.size(); i++)
    {
        freq[s2[i] - 'A']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s1 = "ACT";
    string s2 = "CAT";
    bool ans = isAnagram(s1, s2);
    if (ans)
    {
        cout << "Two strings are anagram of each other" << endl;
    }
    else
    {
        cout << "Two strings are not an anagram of each other" << endl;
    }
    return 0;
}