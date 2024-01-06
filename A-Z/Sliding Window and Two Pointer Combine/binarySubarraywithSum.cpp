#include <bits/stdc++.h>
using namespace std;

// brute force approach
//  class Solution {
//  public:
//      int numSubarraysWithSum(std::vector<int>& nums, int goal) {
//          int n = nums.size();
//          int count = 0;
//          for (int i = 0; i < n; i++) {
//              int sum = 0;
//              for (int j = i; j < n; j++) {
//                  sum = sum + nums[j];
//                  if (sum == goal) {
//                      count++;
//                  }
//              }
//          }
//          return count;
//      }
//  };

// Optimal approach
class Solution
{
public:
    int atMostK(vector<int> &nums, int goal)
    {
        int start = 0;
        int ans = 0;
        int sum = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            sum += nums[end];
            while (sum > goal && start <= end)
            {
                sum -= nums[start];
                start++;
            }
            ans += (end - start + 1);
        }
        return ans;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atMostK(nums, goal) - atMostK(nums, goal - 1);
    }
};

// Input function
std::vector<int> takeInput()
{
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    return nums;
}

int main()
{
    Solution solution;
    std::vector<int> nums = takeInput();

    int goal;
    std::cout << "Enter the goal sum: ";
    std::cin >> goal;

    int result = solution.numSubarraysWithSum(nums, goal);
    std::cout << "Number of subarrays with sum " << goal << ": " << result << std::endl;

    return 0;
}
