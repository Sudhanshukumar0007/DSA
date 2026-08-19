#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dest) {
    int nodes = graph.size();
    
    // Set stores {distance, node} pairs sorted by distance
    set<pair<int, int>> s;
    vector<int> distance(nodes, INT_MAX);

    distance[src] = 0;
    s.insert({0, src});

    while (!s.empty()) {
        // Extract the element with the smallest distance
        auto it = s.begin();
        int currDist = it->first;
        int currNode = it->second;
        s.erase(it);

        // Early exit if destination is reached
        if (currNode == dest) {
            return currDist;
        }

        for (const auto& edge : graph[currNode]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (currDist + weight < distance[neighbor]) {
                // If neighbor already exists in the set with an older distance, remove it
                if (distance[neighbor] != INT_MAX) {
                    s.erase({distance[neighbor], neighbor});
                }

                // Update distance and insert new pair into set
                distance[neighbor] = currDist + weight;
                s.insert({distance[neighbor], neighbor});
            }
        }
    }

    return (distance[dest] == INT_MAX) ? -1 : distance[dest];
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
        graph[v].push_back({u, w});
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

    int ans = dijkstra(graph, src, dest);
    cout << "Minimum distance from source to destination is: " << ans << "\n";

    return 0;
}