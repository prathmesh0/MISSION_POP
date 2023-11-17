#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0;
        for (auto it : nums) {
            ans = ans ^ it;
        }
        return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Input vector of integers
    std::vector<int> nums = {4, 2, 1, 2, 1}; // Example input vector

    // Call the singleNumber function and output the result
    int result = solution.singleNumber(nums);
    std::cout << "The single number in the array is: " << result << std::endl;

    return 0;
}
