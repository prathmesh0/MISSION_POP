#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> &nums, int i, vector<int> &temp, vector<vector<int>> &ans)
{
    // BC
    if (nums.size() == i)
    {
        ans.push_back(temp);
        return;
    }
    // exclude
    helper(nums, i + 1, temp, ans);
    // include
    temp.push_back(nums[i]);
    helper(nums, i + 1, temp, ans);
    // Backtrack
    temp.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int i = 0;
    helper(nums, i, temp, ans);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3}; // Replace with your own integer array
    vector<vector<int>> ans = subsets(nums);

    // Print the generated subsets
    for (const vector<int> &subset : ans)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
