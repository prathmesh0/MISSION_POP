#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        const int N = 444;
        vector<int> adj[N];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis;
        for (int i = 0; i < n; i++)
        {
            vis.push_back(0);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, adj, vis);
            }
        }
        return count;
    }
};

vector<vector<int>> createInput(int n, vector<vector<int>> &isConnectedValues)
{
    vector<vector<int>> isConnected(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            isConnected[i][j] = isConnectedValues[i][j];
        }
    }
    return isConnected;
}

int main()
{
    Solution sol;

    // Example usage:
    int n = 4;
    vector<vector<int>> isConnectedValues = {{1, 1, 0, 0},
                                             {1, 1, 0, 1},
                                             {0, 0, 1, 0},
                                             {0, 1, 0, 1}};
    vector<vector<int>> isConnected = createInput(n, isConnectedValues);

    int result = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl;

    return 0;
}
