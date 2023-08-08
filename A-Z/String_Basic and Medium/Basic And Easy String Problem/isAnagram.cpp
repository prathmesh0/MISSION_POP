#include <bits/stdc++.h>
using namespace std;

//bruteforce approach
// bool isAnagram(string s1, string s2)
// {
//     if (s1.size() != s2.size())
//         return false;
//     sort(s1.begin(), s1.end());
//     sort(s2.begin(), s2.end());
//     for (int i = 0; i < s1.size(); i++)
//     {
//         if (s1[i] != s2[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }

//Optimal approach
bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int freq[26] = {0};
        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i<t.length(); i++){
            freq[t[i] - 'a']--;
        }

        for(int i =0; i< 26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
int main()
{
    string s1 = "cat";
    string s2 = "rct";
    if (isAnagram(s1, s2))
    {
        cout << "Given strings are anagram of each other" << endl;
    }
    else
    {
        cout << "Given strings are not anagram of each other" << endl;
    }

    return 0;
}