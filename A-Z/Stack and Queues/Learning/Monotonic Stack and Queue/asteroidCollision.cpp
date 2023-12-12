#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution
{
public:
    std::vector<int> asteroidCollision(std::vector<int> &asteroids)
    {
        std::vector<int> ans;
        std::stack<int> st;

        for (auto it : asteroids)
        {
            if (it > 0 || st.empty())
            {
                st.push(it);
            }
            else
            {
                while (!st.empty() && st.top() > 0 && abs(it) > st.top())
                {
                    st.pop();
                }

                if (!st.empty() && abs(it) == st.top())
                {
                    st.pop();
                    continue;
                }

                if (st.empty() || st.top() < 0)
                {
                    st.push(it);
                }
            }
        }

        while (!st.empty())
        {
            ans.insert(ans.begin(), st.top());
            st.pop();
        }

        return ans;
    }
};

// Function to take input for the array
std::vector<int> takeInput()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    return arr;
}

int main()
{
    Solution sol;

    // Taking input for the array
    std::vector<int> inputArr = takeInput();

    // Calculating the state after asteroid collision
    std::vector<int> result = sol.asteroidCollision(inputArr);

    // Displaying the result
    std::cout << "State after asteroid collision: ";
    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
