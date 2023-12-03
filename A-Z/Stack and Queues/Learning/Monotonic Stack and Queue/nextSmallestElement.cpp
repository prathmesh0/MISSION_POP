#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Bruteforce
class Solution
{
public:
    std::vector<int> prevSmaller(std::vector<int> &A)
    {
        int n = A.size();
        std::vector<int> ans;
        if (n == 1)
        {
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(-1);
        for (int i = 1; i < A.size(); i++)
        {
            int ele = A[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (A[j] < ele)
                {
                    ele = A[j];
                    break;
                }
            }
            if (ele != A[i])
            {
                ans.push_back(ele);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// Optimal approach
//  vector<int> Solution::prevSmaller(vector<int> &A)
//  {
//      stack<int> st;
//      vector<int> ans;

//     for (int i = 0; i < A.size(); i++)
//     {
//         while (!st.empty() && st.top() >= A[i])
//         {
//             st.pop();
//         }
//         if (st.empty())
//         {
//             ans.push_back(-1);
//         }
//         else
//         {
//             ans.push_back(st.top());
//         }
//         st.push(A[i]);
//     }
//     return ans;
// }

// Input function
void inputFunction()
{
    Solution sol;
    int size;
    std::cout << "Enter the size of A: ";
    std::cin >> size;

    std::vector<int> A(size);
    std::cout << "Enter elements of A:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> A[i];
    }

    std::vector<int> result = sol.prevSmaller(A);

    std::cout << "Previous Smaller Elements are: ";
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
