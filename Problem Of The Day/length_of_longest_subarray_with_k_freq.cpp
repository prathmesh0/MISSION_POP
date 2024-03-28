#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxSubarrayLengthApproach1(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int j = 0; j < n; j++)
        {
            mpp[nums[j]]++;

            while (mpp[nums[j]] > k && i <= j)
            {
                mpp[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }

    int maxSubarrayLengthApproach2(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            unordered_map<int, int> mpp;
            for (int j = i; j < n; j++)
            {
                mpp[nums[j]]++;
                if (mpp[nums[j]] <= k)
                {
                    count++;
                    maxi = max(maxi, count);
                }
                else
                {
                    break;
                }
            }
        }
        return maxi;
    }

    void getInput(vector<int> &nums, int &k)
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        cout << "Enter the elements of the array: ";
        nums.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        cout << "Enter the value of k: ";
        cin >> k;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int k;

    solution.getInput(nums, k);

    int result1 = solution.maxSubarrayLengthApproach1(nums, k);
    cout << "Approach 1 Result: " << result1 << endl;

    int result2 = solution.maxSubarrayLengthApproach2(nums, k);
    cout << "Approach 2 Result: " << result2 << endl;

    return 0;
}
