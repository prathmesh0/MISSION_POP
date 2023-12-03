#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// brute force
//  class Solution {
//  public:
//      int findPosition(std::vector<int> num2, int key) {
//          for (int i = 0; i < num2.size(); i++) {
//              if (num2[i] == key) {
//                  return i;
//              }
//          }
//          return -1;
//      }

// public:
//     std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
//         std::vector<int> ans;
//         for (int i = 0; i < nums1.size(); i++) {
//             int ele = nums1[i];
//             int val = -1;
//             int position = findPosition(nums2, ele);
//             for (int j = position + 1; j < nums2.size(); j++) {
//                 if (nums2[j] > nums1[i]) {
//                     val = nums2[j];
//                     break;
//                 }
//             }
//             ans.push_back(val);
//         }
//         return ans;
//     }
// };

// optimal
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mpp;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            // if current element is greater than stack top
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            // if stack is empty
            if (st.empty())
            {
                mpp[nums2[i]] = -1;
            }
            else
            {
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (auto it : nums1)
        {
            int element = mpp[it];
            ans.push_back(element);
        }
        return ans;
    }
};
// Input function
void inputFunction()
{
    Solution sol;
    int m, n;
    std::cout << "Enter the size of nums1: ";
    std::cin >> m;

    std::vector<int> nums1(m);
    std::cout << "Enter elements of nums1:" << std::endl;
    for (int i = 0; i < m; i++)
    {
        std::cin >> nums1[i];
    }

    std::cout << "Enter the size of nums2: ";
    std::cin >> n;

    std::vector<int> nums2(n);
    std::cout << "Enter elements of nums2:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums2[i];
    }

    std::vector<int> result = sol.nextGreaterElement(nums1, nums2);

    std::cout << "Next Greater Elements of nums1 with respect to nums2 are: ";
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
