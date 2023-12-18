#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxOnes = 0;
//         for(int i = 0; i < n; i++) {
//             int zeros = 0;
//             int j = i;
//             while(j < n) {
//                 if(nums[j] == 0) {
//                     if(zeros < k) {
//                         zeros++;
//                     } else {
//                         break;
//                     }
//                 }
//                 j++;
//             }
//             maxOnes = max(maxOnes, j - i);
//         }
//         return maxOnes;
//     }
// };
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int maxCount = 0;
        int zeroCount = 0;
        while (j < n)
        {
            if (nums[j] == 0)
            {
                zeroCount++;
            }
            while (zeroCount > k)
            {
                if (nums[i] == 0)
                {
                    zeroCount--;
                }
                i++;
            }
            maxCount = max(maxCount, j - i + 1);
            j++;
        }
        return maxCount;
    }
};

// Input function
vector<int> takeInput()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter the elements of the array (0s and 1s only): ";
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    return nums;
}

int main()
{
    Solution sol;
    vector<int> nums = takeInput();
    int k;
    cout << "Enter the maximum number of zeros to flip: ";
    cin >> k;

    int maxLength = sol.longestOnes(nums, k);
    cout << "Maximum number of consecutive 1's after flipping at most " << k << " zeros: " << maxLength << endl;

    return 0;
}
