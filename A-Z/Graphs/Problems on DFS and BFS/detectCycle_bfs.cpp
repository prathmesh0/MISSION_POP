#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
private:
    bool detect(int src, int vis[], vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                } else if (it != parent) {
                    //cycle detect
                    return true;
                }
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, vis, adj) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

