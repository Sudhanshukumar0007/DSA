#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    if (!(cin >> nodes >> edges)) return 0;

    // Adjacency Matrix initialized to 0
    vector<vector<int>> graph(nodes, vector<int>(nodes, 0));

    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        
        // Safety check for 0-based indexing
        if (u >= 0 && u < nodes && v >= 0 && v < nodes) {
            graph[u][v] = 1;
            graph[v][u] = 1; // Undirected graph
        } else {
            cout << "Invalid node indices! Must be between 0 and " << nodes - 1 << endl;
            i--; // Retry this edge input
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}