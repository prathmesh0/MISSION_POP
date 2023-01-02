#include <iostream>
using namespace std;

int isPalindrome(int n)
{
    int ans = 0;
    int x = n;
    while (x != 0)
    {
        int digit = x % 10;
        ans = ans * 10 + digit;
        x /= 10;
    }
    return ans;
}

int main()
{
    int num;
    cin >> num;
    int reversed_no = isPalindrome(num);
    int dummy = num;
    if (reversed_no == dummy)
    {
        cout << "Palindrome number" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}