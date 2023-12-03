#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// class Solution
// {
// public:
//     vector<int> nextGreaterElements(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> temp;
//         vector<int> ans;
//         temp = nums;
//         for (auto it : nums)
//         {
//             temp.push_back(it);
//         }

//         for (int i = 0; i < nums.size(); i++)
//         {
//             int x = temp[i];
//             int j = i + 1;
//             while (j < temp.size())
//             {
//                 if (temp[j] > x)
//                 {
//                     x = temp[j];
//                     break;
//                 }
//                 j++;
//             }
//             if (x != temp[i])
//             {
//                 ans.push_back(x);
//             }
//             else
//             {
//                 ans.push_back(-1);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st;
        
        for(int i = 2* n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i%n] ){
                st.pop();
            }

            if(i < n){
                if(!st.empty()){
                    ans[i] = st.top();
                }
                else{
                    ans[i] = -1;
                }
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};

// Input function
void inputFunction()
{
    Solution sol;
    int size;
    std::cout << "Enter the size of nums: ";
    std::cin >> size;

    std::vector<int> nums(size);
    std::cout << "Enter elements of nums:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> nums[i];
    }

    std::vector<int> result = sol.nextGreaterElements(nums);

    std::cout << "Next Greater Elements are: ";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    inputFunction();
    return 0;
}
