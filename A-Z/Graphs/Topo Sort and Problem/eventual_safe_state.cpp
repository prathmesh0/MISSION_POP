#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<int> revAdj[n];

        // Reverse graph and calculate indegree
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                revAdj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : revAdj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

vector<vector<int>> readGraph()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter the adjacency list for each node:" << endl;
    for (int i = 0; i < n; ++i)
    {
        int m;
        cout << "Enter the number of neighbors for node " << i << ": ";
        cin >> m;

        cout << "Enter the neighbors for node " << i << ": ";
        for (int j = 0; j < m; ++j)
        {
            int neighbor;
            cin >> neighbor;
            graph[i].push_back(neighbor);
        }
    }

    return graph;
}

int main()
{
    Solution solution;
    vector<vector<int>> graph = readGraph();
    vector<int> result = solution.eventualSafeNodes(graph);

    cout << "Eventual safe nodes: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
