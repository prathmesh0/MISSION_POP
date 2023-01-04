#include <iostream>
using namespace std;

bool Palindrome(int i, string &s)
{
    if (i >= (s.size() / 2))
        return true;
    if (s[i] != s[(s.size()) - i - 1])
        return false;
    return Palindrome(i + 1, s);
}

int main()
{
    string s = "madsm";
    bool ans = Palindrome(0, s);
    if (ans)
    {
        cout << "given string is palindrome" << endl;
    }
    else
    {
        cout << "given string is not palindrome" << endl;
    }
    return 0;
}