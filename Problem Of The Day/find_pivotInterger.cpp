#include <iostream>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            long long left_sum = i * (i + 1) / 2;
            long long right_sum = n * (n + 1) / 2 - i * (i - 1) / 2;
            if (left_sum == right_sum)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    Solution sol;
    int pivot = sol.pivotInteger(n);
    if (pivot == -1)
    {
        cout << "No pivot integer found for the given value of n." << endl;
    }
    else
    {
        cout << "The pivot integer for the given value of n is: " << pivot << endl;
    }
    return 0;
}
