#include <iostream>
#include <vector>
#include <climits>
#include<priority_queue>
using namespace std;

// Returns vector of edges in the MST: {{parent, node}, weight}
// using priority queue
vector<pair<pair<int, int>, int>> prims(const vector<vector<pair<int, int>>> &graph, int startNode) {
// {weight, {node, parent}}
    int nodes = graph.size();
    priority_queue<
        pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>
    > pq;
    vector<bool>visited(nodes,false);
    vector<pair<pair<int, int>, int>>mst;
    pq.push(make_pair(0,{startNode,-1}));
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int weight = curr.first;
        int u = curr.second.first;
        int parent = curr.second.second;
        if(visited[u]){
            continue;
        }
        visited[u] = true;
        if(parent!=-1){
            mst.push_back({{parent,u},weight});
        }
        for(auto &edge:graph[u]){
            int v = edge.first;
            int edgeWeight = edge.second;
            if (!visited[v]) {
                pq.push({edgeWeight, {v, u}});
            }
        }
    }
    return mst;
}
vector<pair<pair<int, int>, int>> prims(const vector<vector<pair<int, int>>> &graph, int startNode) {
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    key[startNode] = 0;

    for (int count = 0; count < n; count++) {
        int mini = INT_MAX;
        int u = -1;

        // Pick the minimum key vertex not yet included in MST
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        // Graph is disconnected or remaining vertices are unreachable
        if (u == -1) break;

        inMST[u] = true;

        // Update keys and parents of adjacent vertices
        for (const auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!inMST[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Collect MST edges
    vector<pair<pair<int, int>, int>> result;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            result.push_back({{parent[i], i}, key[i]});
        }
    }
    return result;
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
        // Undirected graph: add edge both ways
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int startNode = 0;
    cout << "Enter the startNode (0 to " << nodes - 1 << "): ";
    cin >> startNode;

    vector<pair<pair<int, int>, int>> mstEdges = prims(graph, startNode);

    int totalWeight = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (const auto &edge : mstEdges) {
        cout << edge.first.first << " - " << edge.first.second << " (Weight: " << edge.second << ")\n";
        totalWeight += edge.second;
    }
    cout << "Total MST Weight: " << totalWeight << "\n";

    return 0;
}