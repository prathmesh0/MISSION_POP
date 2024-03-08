#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, int vis[], int pathVis[], vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            // if adj node is not visited then call the dfs
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, adj) == true) {
                    return true;
                }
            }
            // if the node is visited and it is already marked in the pathVis
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};

        for (int i = 0; i < V; i++) {
            if (dfs(i, vis, pathVis, adj) == true) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Example input
    int V = 4;  // Number of vertices
    int E = 4;  // Number of edges

    // Adjacency list representation of the graph
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0);

    // Create instance of Solution class
    Solution obj;

    // Call the function
    bool result = obj.isCyclic(V, adj);

    // Output the result
    if (result)
        cout << "The graph contains a cycle.\n";
    else
        cout << "The graph does not contain a cycle.\n";

    return 0;
}
