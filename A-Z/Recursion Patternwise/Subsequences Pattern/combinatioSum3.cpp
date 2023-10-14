#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    void helper(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int k, int sum){
        if(ind == nums.size()){
            if(ds.size() == k && sum == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[ind] <= sum){
            ds.push_back(nums[ind]);
            helper(ind+1, nums, ds, ans, k, sum-nums[ind]);
            ds.pop_back();
        }
        helper(ind+1, nums, ds, ans, k, sum);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0, nums, ds, ans, k, n);
        return ans;
    }
};

// Input function for the combinationSum3 function
std::pair<int, int> getInput() {
    int k, n;
    std::cout << "Enter the value of k: ";
    std::cin >> k;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    
    return std::make_pair(k, n);
}

int main() {
    std::pair<int, int> input = getInput();
    int k = input.first;
    int n = input.second;

    Solution solution;
    vector<vector<int>> result = solution.combinationSum3(k, n);

    // Print the result
    for (const vector<int>& combination : result) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
