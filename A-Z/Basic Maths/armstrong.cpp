#include <iostream>
#include <math.h>
using namespace std;

bool ArmstrongNo(int num)
{
    int count = 0;
    int ori = num;
    int temp = num;
    // counting number of digits
    while (temp != 0)
    {
        temp = temp / 10;
        count++;
    }
    int sumOfpower = 0;
    while (num != 0)
    {
        int digit = num % 10;
        sumOfpower = sumOfpower + pow(digit, count);
        num /= 10;
    }
    return (sumOfpower == ori);
}

int main()
{
    int num;
    cin >> num;
    bool ans = ArmstrongNo(num);
    if (ans)
        cout << "Given Number is armstrong number " << endl;
    else
        cout << "Given Number is not armstrong number " << endl;
    return 0;
}