#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // Remove all elements which are out of the bound of the sliding window
            while (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

// Function to input the vector and k
pair<vector<int>, int> getInput() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    return { nums, k };
}

int main() {
    Solution solution;
    
    // Getting input
    pair<vector<int>, int> input = getInput();

    // Obtaining results using maxSlidingWindow function
    vector<int> result = solution.maxSlidingWindow(input.first, input.second);

    // Displaying the result
    cout << "The maximum sliding window values are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
