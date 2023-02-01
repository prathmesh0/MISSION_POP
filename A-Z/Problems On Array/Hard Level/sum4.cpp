#include <bits/stdc++.h>
using namespace std;

/*
//brute-force approach
vector<vector<int>> fourSum(vector<int> nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    set<vector<int>> sv;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int x = (long long)target -
                        (long long)nums[i] -
                        (long long)nums[j] -
                        (long long)nums[k];
                if (binary_search(nums.begin() + k + 1, nums.end(), x))
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(x);
                    sort(v.begin(), v.end());
                    sv.insert(v);
                }
            }
        }
    }
    vector<vector<int>> res(sv.begin(), sv.end());
    return res;
}
*/
// optimal approach
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;

    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {

        long long int target_3 = target - nums[i];

        for (int j = i + 1; j < n; j++)
        {
            long long int target_2 = target_3 - nums[j];
            int front = j + 1;
            int back = n - 1;

            while (front < back)
            {
                int two_sum = nums[front] + nums[back];

                if (two_sum < target_2)
                    front++;

                else if (two_sum > target_2)
                    back--;

                else
                {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[front];
                    quadruplet[3] = nums[back];
                    ans.push_back(quadruplet);

                    // Processing the duplicates of number 3
                    while (front < back && nums[front] == quadruplet[2])
                        ++front;

                    // Processing the duplicates of number 4
                    while (front < back && nums[back] == quadruplet[3])
                        --back;
                }
            }
            // Processing the duplicates of number 2
            while (j + 1 < n && nums[j + 1] == nums[j])
                ++j;
        }
        // Processing the duplicates of number 1
        while (i + 1 < n && nums[i + 1] == nums[i])
            ++i;
    }
    return ans;
}

int main()
{
    vector<int> v{1, 0, -1, 0, -2, 2};

    vector<vector<int>> sum = fourSum(v, 0);
    cout << "The unique quadruplets are" << endl;
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
    return 0;
}