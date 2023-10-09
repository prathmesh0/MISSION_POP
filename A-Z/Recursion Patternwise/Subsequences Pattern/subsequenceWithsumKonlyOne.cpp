#include <bits/stdc++.h>
using namespace std;

// Using global variable
//  int flag = false;
//  void subsequence(vector<int> &v, int sum, vector<int> &ds, int ind, int s, int n)
//  {
//      // BC
//      if (ind == n)
//      {
//          if (sum == s && flag == false)
//          {
//              for (auto it : ds)
//              {
//                  cout << it << " ";
//              }
//              cout << endl;
//              flag = true;
//          }
//          return;
//      }

//     // Include
//     ds.push_back(v[ind]);
//     s += v[ind];
//     subsequence(v, sum, ds, ind + 1, s, n);
//     // Exclude
//     s -= v[ind];
//     ds.pop_back();
//     subsequence(v, sum, ds, ind + 1, s, n);
// }

// Using functional way
bool subsequence(vector<int> &v, int sum, vector<int> &ds, int ind, int s, int n)
{
    // BC
    if (ind == n)
    {
        if (sum == s)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    // Include
    ds.push_back(v[ind]);
    s += v[ind];
    if (subsequence(v, sum, ds, ind + 1, s, n) == true)
    {
        return true;
    }
    // Exclude
    s -= v[ind];
    ds.pop_back();
    if (subsequence(v, sum, ds, ind + 1, s, n) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int> v = {1, 2, 1};
    int sum = 2;
    int n = 3;
    vector<int> ds;
    subsequence(v, sum, ds, 0, 0, n);
    return 0;
}