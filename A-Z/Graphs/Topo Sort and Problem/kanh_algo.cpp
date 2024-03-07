#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        queue<int> q;

        // Calculating indegree for each vertex
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Pushing vertices with 0 indegree into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Processing vertices in the queue
        while (!q.empty()) {
            int ele = q.front();
            q.pop();
            ans.push_back(ele);

            // Reducing indegree of adjacent vertices and pushing them into the queue if indegree becomes 0
            for (auto it : adj[ele]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

int main() {
    // Example input
    int T;
    cin >> T;
    while (T--) {
        int E, N;
        cin >> E >> N;

        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        // Output 1 if the returned topological sort is valid, 0 otherwise
        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
