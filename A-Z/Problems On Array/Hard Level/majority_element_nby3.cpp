#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
// brute force approach
vector<int> majority(int arr[], int n)
{
    vector<int> ans;
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > (n / 3))
            ans.push_back(arr[i]);
    }
    return ans;
}

// Better approach
vector<int> majority(int arr[], int n)
{
    unordered_map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > (n / 3))
            ans.push_back(it.first);
    }
    return ans;
}
*/

// optimal solution
vector<int> majority(int nums[], int n)
{
    int sz = n;
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0, i;
    for (i = 0; i < sz; i++)
    {
        if (nums[i] == num1)
            c1++;
        else if (nums[i] == num2)
            c2++;
        else if (c1 == 0)
        {
            num1 = nums[i];
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = nums[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    vector<int> ans;
    c1 = c2 = 0;
    for (i = 0; i < sz; i++)
    {
        if (nums[i] == num1)
            c1++;
        else if (nums[i] == num2)
            c2++;
    }
    if (c1 > sz / 3)
        ans.push_back(num1);
    if (c2 > sz / 3)
        ans.push_back(num2);
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
    ans = majority(arr, n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}