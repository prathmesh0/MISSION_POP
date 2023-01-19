#include <iostream>
#include <vector>
using namespace std;

vector<int> Two_sum(int arr[], int n, int k)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                ans.emplace_back(i);
                ans.emplace_back(j);
                break;
            }
        }
        if (ans.size() == 2)
            break;
    }
    return ans;
}

// better approach
vector<int> Two_sum(vector<int> &nums, int target)
{
    vector<int> res, store;
    store = nums;
    sort(store.begin(), store.end());
    int left = 0, right = nums.size() - 1;
    int n1, n2;
    while (left < right)
    {
        if (store[left] + store[right] == target)
        {
            n1 = store[left];
            n2 = store[right];
            break;
        }
        else if (store[left] + store[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == n1)
            res.emplace_back(i);
        else if (nums[i] == n2)
            res.emplace_back(i);
    }
    return res;
}

int main()
{
    int n, k;
    int arr[10000];
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v;
    v = Two_sum(arr, n, k);
    for (auto it : v)
        cout << it << " ";
    return 0;
}