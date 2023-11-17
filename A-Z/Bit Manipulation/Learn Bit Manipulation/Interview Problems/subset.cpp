#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;

        int n = nums.size();
        for (int num = 0; num < (1 << n); num++) {
            std::vector<int> ds;
            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    ds.push_back(nums[i]);
                }
            }
            ans.push_back(ds);
        }

        return ans;
    }
};

void printSubsets(const std::vector<std::vector<int>>& subsets) {
    std::cout << "All possible subsets are:" << std::endl;
    for (const auto& subset : subsets) {
        std::cout << "[";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    Solution solution;

    // Input vector of integers
    std::vector<int> nums = {1, 2, 3}; // Example input

    // Get subsets using the Solution class method
    std::vector<std::vector<int>> result = solution.subsets(nums);

    // Print the generated subsets
    printSubsets(result);

    return 0;
}
