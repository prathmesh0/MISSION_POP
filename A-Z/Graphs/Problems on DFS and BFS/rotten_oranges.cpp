#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    tot++;
                }
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!rotten.empty())
        {
            int k = rotten.size();
            cnt += k;

            while (k--)
            {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    {
                        continue;
                    }
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if (!rotten.empty())
                days++;
        }
        return tot == cnt ? days : -1;
    }
};

vector<vector<int>> createInput(vector<vector<int>> &gridValues)
{
    vector<vector<int>> grid;
    for (const auto &row : gridValues)
    {
        grid.push_back(row);
    }
    return grid;
}

int main()
{
    Solution sol;

    // Example usage:
    vector<vector<int>> gridValues = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    vector<vector<int>> grid = createInput(gridValues);

    int result = sol.orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}
