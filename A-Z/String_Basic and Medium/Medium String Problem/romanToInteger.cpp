#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> T = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    int num, sum = 0;
    for (int i = 0; i < s.length();)
    {
        if (i == (s.length() - 1) || T[s[i]] >= T[s[i + 1]])
        {
            num = T[s[i]];
            i++;
        }
        else
        {
            num = T[s[i + 1]] - T[s[i]];
            i = i + 2;
        }
        sum = sum + num;
    }
    return sum;
}

int main()
{
    string s = "XXIV";
    cout<<romanToInt(s)<<endl;
    
    return 0;
}