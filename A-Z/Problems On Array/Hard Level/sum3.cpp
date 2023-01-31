#include <bits/stdc++.h>
using namespace std;

/*
//brute force approach
vector<vector<int>> threeSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                temp.clear();
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                }
                if (temp.size() != 0)
                    ans.push_back(temp);
            }
        }
    }
    return ans;
}

// Hashing solution in c++
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    if (n == 0 || n < 3)
        return ans;

    unordered_map<int, int> ump;

    for (auto num : nums)
    {
        ump[num]++;
    }
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        ump[nums[i]]--;
        for (int j = i + 1; j < n; j++)
        {
            ump[nums[j]]--;
            int c = -(nums[i] + nums[j]);
            if (ump.find(c) != ump.end() && ump[c] > 0)
            {
                vector<int> temp = {nums[i], nums[j], c};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            ump[nums[j]]++;
        }
        ump[nums[i]]++;
    }
    ans.assign(s.begin(), s.end());
    return ans;
}
*/
// optimal approach
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    // moves for a
    for (int i = 0; i < (int)(nums.size()) - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int lo = i + 1, hi = nums.size() - 1, sum = 0 - nums[i];
            while (lo < hi)
            {
                // equal to sum
                if (nums[lo] + nums[hi] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    ans.push_back(temp);
                    while (lo < hi && nums[lo] == nums[lo + 1])
                        lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1])
                        hi--;
                    lo++;
                    hi--;
                }

                // less than sum
                else if (nums[lo] + nums[hi] < sum)
                    lo++;
                // greater than sum
                else
                    hi--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    ans = threeSum(arr);
    cout << "The triplets are as follows: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}