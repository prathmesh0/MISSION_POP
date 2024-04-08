#include <iostream>
#include <vector>

#define ll long long

using namespace std;

class Solution
{
public:
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        ll src = 0;
        // create an adjancy list
        vector<pair<ll, ll>> adj[n];
        for (auto it : roads)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // time is very --> so we use the  priority queue..
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        // push the things--> {dis ,node}
        pq.push({0, 0});

        // make the distance vector
        vector<ll> dist(n, LLONG_MAX);
        dist[src] = 0;
        // make the ways vector
        vector<ll> ways(n, 0);
        ways[src] = 1;

        while (!pq.empty())
        {
            ll dis = pq.top().first;
            ll curr_node = pq.top().second;
            pq.pop();

            for (auto it : adj[curr_node])
            {
                ll neighnode = it.first;
                ll wt = it.second;

                if (dis + wt < dist[neighnode])
                {
                    dist[neighnode] = dis + wt;
                    pq.push({dist[neighnode], neighnode});
                    ways[neighnode] = ways[curr_node];
                }

                else if (dis + wt == dist[neighnode])
                {
                    ways[neighnode] = (ways[neighnode] + ways[curr_node]) % M;
                }
            }
        }
        return ways[n - 1] % M;
    }
};

// Input function
vector<vector<int>> getInput()
{
    vector<vector<int>> roads;
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of roads: ";
    cin >> m;
    cout << "Enter the roads in format (u, v, wt):" << endl;
    for (int i = 0; i < m; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        roads.push_back({u, v, wt});
    }
    return roads;
}

int main()
{
    Solution obj;
    int n;
    vector<vector<int>> roads = getInput();
    cout << "Enter the number of nodes: ";
    cin >> n;
    int result = obj.countPaths(n, roads);
    cout << "Number of paths modulo 1e9 + 7: " << result << endl;
    return 0;
}
