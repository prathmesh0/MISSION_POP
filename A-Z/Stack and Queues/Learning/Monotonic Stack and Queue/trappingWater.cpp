#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
// class Solution {
// public:
//     int trap(std::vector<int>& height) {
//         int n = height.size();
//         int trapeWater = 0;

//         for(int i = 0; i < n; i++) {
//             int j = i;
//             int leftMax = 0, rightMax = 0;
//             //left nearest maximum height
//             while(j >= 0) {
//                 leftMax = std::max(leftMax, height[j]);
//                 j--;
//             }
//             j = i;
//             while(j < n) {
//                 rightMax = std::max(rightMax, height[j]);
//                 j++;
//             }
//             trapeWater += std::min(leftMax, rightMax) - height[i];
//         }
//         return trapeWater;
//     }
// };

// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int n = height.size();
//         vector<int> prefix(n, 0);
//         vector<int> suffix(n, 0);
//         int trapeWater = 0;

//         prefix[0] = height[0];
//         for (int i = 1; i < n; i++)
//         {
//             prefix[i] = max(prefix[i - 1], height[i]);
//         }
//         suffix[n - 1] = height[n - 1];
//         for (int i = n - 2; i >= 0; i--)
//         {
//             suffix[i] = max(suffix[i + 1], height[i]);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             trapeWater += min(prefix[i], suffix[i]) - height[i];
//         }
//         return trapeWater;
//     }
// };
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxleft = 0, maxright = 0;
        int res = 0;
        while(left <= right){
          if(height[left] <= height[right]){
            if(height[left] >= maxleft){
              maxleft = height[left];
            }
            else{
              res +=  maxleft - height[left];
            }
            left++;
          }
          else{
            if(height[right] >= maxright){
              maxright= height[right];
            }
            else{
              res +=  maxright - height[right];
            }
            right--;
        }
        } 
        return res;
    }
};
std::vector<int> parseInput(std::string input)
{
    std::vector<int> height;
    std::stringstream ss(input);
    int num;
    while (ss >> num)
    {
        height.push_back(num);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return height;
}

int main()
{
    std::string input;
    std::cout << "Enter heights separated by commas: ";
    std::getline(std::cin, input);

    std::vector<int> height = parseInput(input);

    Solution solution;
    int result = solution.trap(height);

    std::cout << "Total trapped water: " << result << std::endl;

    return 0;
}
