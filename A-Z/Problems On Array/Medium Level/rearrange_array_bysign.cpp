#include <iostream>
#include <vector>
using namespace std;

// brute force approach
/*
vector<int> rearrange_array(int arr[], int n)
{
    vector<int> v1, v2, v3;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            v1.push_back(arr[i]);
        else
            v2.push_back(arr[i]);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        v3.push_back(v2[i]);
        v3.push_back(v1[i]);
    }
    return v3;
}
*/
// using two pointer approach
vector<int> rearrange_array(int arr[], int n)
{
    int even = 0, odd = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[even] = arr[i];
            even += 2;
        }

        else
        {
            ans[odd] = arr[i];
            odd += 2;
        }
    }

    return ans;
}

int main()
{
    int n;
    int arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    ans = rearrange_array(arr, n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}