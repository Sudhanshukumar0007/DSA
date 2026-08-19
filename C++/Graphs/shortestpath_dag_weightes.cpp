#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

void topoSort(const vector<vector<pair<int, int>>>& graph, int u, vector<bool>& visited, stack<int>& order) {
    visited[u] = true;
    for (const auto& edge : graph[u]) {
        int v = edge.first;
        if (!visited[v]) {
            topoSort(graph, v, visited, order);
        }
    }
    order.push(u);
}

int shortestPathDAG(const vector<vector<pair<int, int>>>& graph, int source, int dest) {
    int nodes = graph.size();
    vector<bool> visited(nodes, false);
    stack<int> order;

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            topoSort(graph, i, visited, order);
        }
    }

    // Initialize distances
    vector<int> dist(nodes, INT_MAX);
    dist[source] = 0;

    while (!order.empty()) {
        int u = order.top();
        order.pop();

        if (dist[u] != INT_MAX) {
            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    return (dist[dest] == INT_MAX) ? -1 : dist[dest];
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    if (!(cin >> nodes >> edges)) return 0;

    vector<vector<pair<int, int>>> graph(nodes);

    cout << "Enter " << edges << " edges (u v w):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (const auto& edge : graph[i]) {
            cout << "[" << edge.first << ", " << edge.second << "] ";
        }
        cout << "\n";
    }

    int src, dest;
    cout << "\nEnter source and destination: ";
    cin >> src >> dest;

    int ans = shortestPathDAG(graph, src, dest);
    if (ans == -1) {
        cout << "Destination " << dest << " is unreachable from " << src << ".\n";
    } else {
        cout << "Shortest path distance from " << src << " to " << dest << ": " << ans << "\n";
    }

    return 0;
}