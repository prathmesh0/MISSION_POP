#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     int numberOfSubarrays(std::vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int oddcnt = 0;
//             for (int j = i; j < n; j++)
//             {
//                 if (nums[j] % 2 == 1)
//                 {
//                     oddcnt++;
//                 }
//                 if (oddcnt == k)
//                 {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int atMostK(vector<int> &nums, int k)
    {
        int start = 0;
        int kCount = 0;
        int ans = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            if (nums[end] % 2 == 1)
            {
                kCount++;
            }
            while (kCount > k && start <= end)
            {
                if (nums[start] % 2 == 1)
                {
                    kCount--;
                }

                start++;
            }

            ans += (end - start + 1);
        }
        return ans;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
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

    int k;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    int result = solution.numberOfSubarrays(nums, k);
    std::cout << "Number of subarrays with " << k << " odd numbers: " << result << std::endl;

    return 0;
}
