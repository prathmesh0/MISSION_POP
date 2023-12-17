#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

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
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxA;
    }
};

vector<vector<char>> getInputMatrix()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<char>> matrix(rows, vector<char>(cols));
    cout << "Enter the matrix elements row by row (each row of length " << cols << "):" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

int main()
{
    // Create an instance of the Solution class if needed
    // Call the getInputMatrix() function to get the matrix input
    return 0;
}
