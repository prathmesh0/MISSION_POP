#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // Create an adjacency list
        vector<pair<int, int>> adj[n + 1];

        // Populate adjacency list
        for (auto it : times)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); // distance, node
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int neighbourNode = it.first;
                int wt = it.second;

                if (time + wt < dist[neighbourNode])
                {
                    dist[neighbourNode] = time + wt;
                    pq.push({dist[neighbourNode], neighbourNode});
                }
            }
        }
        // Find max from distance array
        int mx = *max_element(dist.begin() + 1, dist.end());
        return mx == INT_MAX ? -1 : mx;
    }
};

// Input function
vector<vector<int>> getInput()
{
    vector<vector<int>> times;
    int n, k;
    cout << "Enter the number of edges: ";
    cin >> n;
    cout << "Enter the source node: ";
    cin >> k;
    cout << "Enter the edges in format (u, v, wt):" << endl;
    for (int i = 0; i < n; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        times.push_back({u, v, wt});
    }
    return times;
}

int main()
{
    Solution obj;
    int n, k;
    vector<vector<int>> times = getInput();
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the source node: ";
    cin >> k;
    int result = obj.networkDelayTime(times, n, k);
    cout << "Maximum network delay time: " << result << endl;
    return 0;
}
