#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// Function to take input for the grid
vector<vector<int>> takeInputGrid()
{
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter the elements of the grid row by row (0 or 1):\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    return grid;
}

int main()
{
    // Take input grid
    vector<vector<int>> grid = takeInputGrid();

    // Create instance of Solution class
    Solution sol;

    // Call the function
    int result = sol.numEnclaves(grid);

    // Output the result
    cout << "The number of enclaves is: " << result << endl;

    return 0;
}
