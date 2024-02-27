#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& ans, int vis[]) {
        vis[node] = 1;
        ans.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, ans, vis);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        int *vis = new int[V]; // Dynamically allocate memory for vis array
        memset(vis, 0, sizeof(int) * V); // Initialize vis array with 0
        int start = 0;
        dfs(start, adj, ans, vis);

        delete[] vis; // Free dynamically allocated memory
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
