#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int nodes = n + 1;

    // for undircted graph
    //  using Matrix
    //   int adj[1000][1000];
    //   // int adj[nodes][nodes];
    //   for (int i = 0; i < m; i++)
    //   {
    //       int u, v;
    //       cin >> u >> v;
    //       adj[u][v] = 1;
    //       adj[v][u] = 1;
    //   }

    // using List/Vector
    // vector<int> adj(n + 1);
    // for (int i = 0; i < m; i++)
    // {
    //     int v, u;
    //     adj.push_back(u);
    //     adj.push_back(v);
    // }

    // for dircted graph
    vector<int> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        adj.push_back(u);
    }
    return 0;
}