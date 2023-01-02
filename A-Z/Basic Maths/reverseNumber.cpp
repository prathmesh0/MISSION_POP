#include <iostream>
using namespace std;

// leetcode reverse number
// if my reversed number is going out of the range then function retruns zero
int reverse(int x)
{
    int ans = 0;
    while (x != 0)
    {
        int digit = x % 10;

        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
        {
            return 0;
        }
        ans = (ans * 10) + digit;
        x = x / 10;
    }
    return ans;
}

int main()
{
    int num;
    int reverse = 0;
    cin >> num;
    while (num != 0)
    {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }
    cout << "Reverse number is " << reverse << endl;

    return 0;
}