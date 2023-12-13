#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//  class Solution
// {
//     public :
//         int largestRectangleArea(std::vector<int> & heights){
//             int n = heights.size();
// int maxArea = 0;
// for (int i = 0; i < n; i++)
// {
//     int minHeight = INT_MAX;
//     for (int j = i; j < n; j++)
//     {
//         minHeight = std::min(minHeight, heights[j]);
//         maxArea = std::max(maxArea, (minHeight * (j - i + 1)));
//     }
// }
// return maxArea;
// }
// }
// ;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];
        // leftsmall
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                leftsmall[i] = 0;

            else
                leftsmall[i] = st.top() + 1;

            st.push(i);
        }

        // remove all elements from stack
        while (!st.empty())
        {
            st.pop();
        }
        // right small
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                rightsmall[i] = n - 1;
            else
                rightsmall[i] = st.top() - 1;
            st.push(i);
        }

        // calculate the area
        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            maxA = std::max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxA;
    }
};
// Input function
std::vector<int> getInput()
{
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> heights(n);
    std::cout << "Enter the heights: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> heights[i];
    }

    return heights;
}

int main()
{
    Solution solution;

    // Getting input
    std::vector<int> heights = getInput();

    // Calculating the largest rectangle area
    int result = solution.largestRectangleArea(heights);

    std::cout << "The largest rectangle area is: " << result << std::endl;

    return 0;
}
