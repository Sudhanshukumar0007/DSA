// Bridge is the edge when removed forms two dissconnected components in a graph or let us just say it makes graph dissconnected 

// Brute force approach is to remove each edge and then check if the graph is still connected if not the it is bridge we can use dfs for checking the connectivity.

// What we do is we make four vectors to track the 
// Discovery Time : The time when we found the node first
// Lowest time : Minimum time to reach the node
// Parent : Parent array of the nodes
// visited : visited array to track which nodes are visited 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, const vector<vector<int>>& graph, vector<int>& disc, vector<int>& low, 
         int parent, int& timer, vector<vector<int>>& result, vector<bool>& vis) {
    vis[u] = true;
    disc[u] = low[u] = timer++;

    for (int nbr : graph[u]) {
        // Skip the edge leading back to the immediate parent
        if (nbr == parent) {
            continue;
        }

        if (!vis[nbr]) {
            // Forward edge (DFS tree edge)
            dfs(nbr, graph, disc, low, u, timer, result, vis);
            
            // On return, propagate the lowest reachable time
            low[u] = min(low[u], low[nbr]);

            // Bridge condition: no path from nbr or its subtree reaches u or above
            if (low[nbr] > disc[u]) {
                result.push_back({u, nbr});
            }
        } else {
            // Back edge: update low[u] using the discovery time of the visited neighbor
            low[u] = min(low[u], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(const vector<vector<int>>& graph) {
    int n = graph.size();
    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> vis(n, false);
    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, graph, disc, low, -1, timer, result, vis);
        }
    }

    return result;
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    if (!(cin >> nodes >> edges)) return 0;

    vector<vector<int>> graph(nodes);
    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    vector<vector<int>> bridges = findBridges(graph);

    cout << "\nBridges in the graph:\n";
    for (const auto& edge : bridges) {
        cout << edge[0] << " -- " << edge[1] << "\n";
    }

    return 0;
}