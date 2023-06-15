#include <bits/stdc++.h>
using namespace std;

int countDigit(int num)
{
    // 928 ->3
    int x = num;
    if (x == 0)
        return 1;
    int count = 0;
    while (x != 0)
    {
        x = x / 10;
        count++;
    }
    return count;
}

int reverseNum(int num)
{
    // 934 ->439
    int ans = 0;
    while (num != 0)
    {
        int digit = num % 10;
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
        {
            return 0;
        }
        ans = ans * 10 + digit;
        num /= 10;
    }
    return ans;
    // sometimes ans*10 exceed the range of an integer
    // that means 1) ans*10>INT_MAX 2)ans*10 <INT_MIN
    // ans >INT_MAX/10 or ans <INT_MIN/10 return 0;
}

bool isPalindrome(int num)
{
    int x = num;
    int reverse = 0;
    while (x != 0)
    {
        int digit = x % 10;
        reverse = reverse * 10 + digit;
        x /= 10;
    }
    if (reverse == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isArmStrong(int num)
{
    // 153 ->1^3+5^3+3^3 = 153 ==>Armstrong number
    // 42->4^2+2^2 = 20 ==>not Armstrong number
    int x = num;
    int ogn = num;
    int digit = 0;
    while (x)
    {
        x /= 10;
        digit++;
    }
    int sumpower = 0;
    while (num != 0)
    {
        int lastdigit = num % 10;
        sumpower += pow(lastdigit, digit);
        num /= 10;
    }
    return (sumpower == ogn);
}

void printDivisor(int num)
{
    // iterative approach with TC = O(n)
    //  for(int i = 1; i<=num; i++){
    //      if(num% i== 0){
    //          cout<<i<<endl;
    //      }
    //  }

    // TC = O(root n)
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            cout << i << endl;
            if (i != num / i)
            {
                cout << (num / i) << endl;
            }
        }
    }
}

bool isPrime(int num)
{
    // TC = O(N)
    //  for (int i = 2; i < num; i++){
    //      if(num % i  == 0) return false;
    //  }
    // return true;

    // TC = O(root N)
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int gcd(int num1, int num2)
{
    // int ans = 1;
    // for (int i = 1; i <= min(num1, num2); i++)
    // {
    //     if (num1 % i == 0 && num2 % i == 0)
    //     {
    //         ans = i;
    //     }
    // }
    // return ans;

    if (num2 == 0) {
		return num1;
	}
	return gcd(num2, num1 % num2);
}
int main()
{
    int n;
    cin>>n;
    int ans = countDigit(n);
    cout << ans << endl;

        int reversen = reverseNum(n);
        cout<<reversen<<endl;

        bool pali = isPalindrome(n);
        if(pali)
        cout<<"Given number is Palindrome"<<endl;
        else
        cout<<"Given number is not Palindrome"<<endl;

        bool armstrong = isArmStrong(n);
        if(armstrong)
        cout<<"Given number is Armstrong Number"<<endl;
        else
        cout<<"Given number is not Armstrong Number"<<endl;

        printDivisor(n);

        bool prime = isPrime(n);
        cout << prime << endl;

        int n1, n2;
        cin >> n1;
        cin>>n2;
        int gcdn = gcd(n1, n2);
        cout<<"gcd = "<<gcdn<<endl;
    return 0;
}