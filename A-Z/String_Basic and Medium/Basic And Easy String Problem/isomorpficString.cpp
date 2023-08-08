#include <bits/stdc++.h>
using namespace std;

//Bruteforce Approach
// bool isIsomorphic(string s, string t)
// {
//     if (s.length() != t.length())
//     {
//         return false;
//     }
//     for (int i = 0; i < s.length(); i++)
//     {
//         for (int j = 0; j < s.length(); j++)
//         {
//             if ((s[i] == s[j] && t[i] != t[j]) || (s[i] != s[j] && t[i] == t[j]))
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// Optimal approach
bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    unordered_map<char, char> c_to_c;
    unordered_map<char, bool> c_to_b;

    for (int i = 0; i < s.length(); i++)
    {
        char s_char = s[i];
        char t_char = t[i];

        // check if char is already mapped into c_to_c
        if (c_to_c.find(s_char) != c_to_c.end())
        {
            // char is already mapped to a different character in t
            if (c_to_c[s_char] != t_char)
            {
                return false;
            }
        }

        else
        {
            // Check if t_char is already mapped to a different character in s
            if (c_to_b.find(t_char) != c_to_b.end() && c_to_b[t_char])
            {
                return false;
            }
            else
            {
                c_to_c[s_char] = t_char;
                c_to_b[t_char] = true;
            }
        }
    }
    return true;
}
int main()
{
    string s = "egg";
    string t = "add";
    if (isIsomorphic(s, t))
    {
        cout << "given string is isomorphic" << endl;
    }
    else
    {
        cout << "given string is not isomorphic" << endl;
    }
    return 0;
}