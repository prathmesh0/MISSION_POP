#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = color;
        for (auto neighbor : graph[node]) {
            if (vis[neighbor] == -1) {
                if (!dfs(neighbor, !color, graph, vis)) {
                    return false;
                }
            } else if (vis[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        // Component traversal
        for (int i = 0; i < n; ++i) {
            if (vis[i] == -1) {
                if (!dfs(i, 0, graph, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};

// Function to take input for the graph
vector<vector<int>> takeInputGraph() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter the adjacency list for each node (enter -1 to terminate):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Enter adjacency list for node " << i << ": ";
        int neighbor;
        while (true) {
            cin >> neighbor;
            if (neighbor == -1)
                break;
            graph[i].push_back(neighbor);
        }
    }

    return graph;
}

int main() {
    // Take input graph
    vector<vector<int>> graph = takeInputGraph();

    // Create instance of Solution class
    Solution sol;

    // Call the function
    bool result = sol.isBipartite(graph);

    // Output the result
    if (result)
        cout << "The graph is bipartite.\n";
    else
        cout << "The graph is not bipartite.\n";
    
    return 0;
}
