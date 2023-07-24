#include <iostream>
#include <math.h>
using namespace std;

// Brute force approach
//  int nthRoot(int n, int m){

//     if (m < 0 && n % 2 == 0) {
//         return -1;
//     }
//     if(n == 1){
//         return m;
//     }
//     for(int i = 1; i<m; i++){
//         int power = pow(i, n);
//         if(power == m){
//             return i;
//         }
//     }
//     return -1;
// }

// Optimal approoach

int func(int mid,int n, int m){
    long long ans = 1;
    for(int i =1; i<=n; i++){
        ans = ans*mid;
        if(ans > m){
            return 2;
        }
    }
    if(ans == m) return 1;
    return 0;
}
int nthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
            return mid;
        else if (midN == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = nthRoot(n, m);
    cout << ans << endl;
    return 0;
}