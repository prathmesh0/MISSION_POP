#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // Approach 1: Floyd's Tortoise and Hare (Cycle Detection)
    int findDuplicate1(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

    // Approach 2: Sorting
    int findDuplicate2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }
        return -1;
    }

    // Approach 3: Using HashSet
    int findDuplicate3(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto it : nums)
        {
            if (st.find(it) != st.end())
            {
                return it;
            }
            st.insert(it);
        }
        return -1;
    }
};

// Input function to create vector from array
vector<int> createVector(int arr[], int n)
{
    vector<int> nums(arr, arr + n);
    return nums;
}

int main()
{
    int arr[] = {1, 3, 4, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> nums = createVector(arr, n);
    Solution sol;

    cout << "Duplicate using Floyd's Tortoise and Hare: " << sol.findDuplicate1(nums) << endl;
    cout << "Duplicate using Sorting: " << sol.findDuplicate2(nums) << endl;
    cout << "Duplicate using HashSet: " << sol.findDuplicate3(nums) << endl;

    return 0;
}
