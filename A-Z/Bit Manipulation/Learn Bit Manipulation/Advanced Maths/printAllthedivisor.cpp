#include <iostream>
#include <vector>
#include <cmath> // Include cmath for sqrt function
#include <algorithm>
using namespace std;

// Brute force approach
//  vector<int> printDivisors(int n) {
//      vector<int>ans;
//      for(int i = 1; i<=n; i++){
//          if(n %i == 0){
//              ans.push_back(i);

//         }
//     }
//     return ans;
// }

// Optimal Aprroach
vector<int> printDivisors(int n)
{
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
            {
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    ans = printDivisors(n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}