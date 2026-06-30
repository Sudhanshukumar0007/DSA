#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<int>& visited, int n) {
    visited[u] = 1;
    cout << u << " ";

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v, adj, visited, n);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cin >> start;

    vector<int> visited(n, 0);

    dfs(start, adj, visited, n);

    return 0;
}
