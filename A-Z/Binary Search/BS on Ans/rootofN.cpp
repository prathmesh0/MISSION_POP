#include <iostream>
#include <math.h>
using namespace std;

// brute force approach
// int squareRoot(int n)
// {
//     int ans = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (i * i <= n)
//         {
//             ans = i;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return ans;
// }

// Brute force approach
// int squareRoot(int n)
// {
//     int ans = sqrt(n);
//     return ans;
// }

// Optimal  approach
int squareRoot(int n)
{
    int low = 0;
    int high = n;
    long long int ans = -1;

    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        long long int square = mid * mid;
        if (square <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int ans = squareRoot(n);
    cout << ans << endl;
    return 0;
}