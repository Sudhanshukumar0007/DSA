#include <iostream>
#include <vector>
#include <stack>
#include <queue> // Needed for BFS

using namespace std;

// ------------------- DFS APPROACH -------------------
void dfs(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& s, int u) {
    visited[u] = true;
    for (int neighbour : graph[u]) {
        if (!visited[neighbour]) {
            dfs(graph, visited, s, neighbour);
        }
    }
    s.push(u);
}

void TopologicalSortdfs(vector<vector<int>>& graph) {
    int nodes = graph.size();
    stack<int> order;
    vector<bool> visited(nodes, false);

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(graph, visited, order, i);
        }
    }

    cout << "\nValid Topological order (DFS): \n";
    while (!order.empty()) {
        cout << order.top() << " ";
        order.pop();
    }
    cout << endl;
}

// ------------------- BFS (KAHN'S ALGORITHM) -------------------
void TopologicalSortbfs(vector<vector<int>>& graph, vector<int> indegree) {
    int nodes = graph.size();
    queue<int> q;
    vector<int> ans;

    // 1. Push all nodes with indegree = 0 to the queue
    for (int i = 0; i < nodes; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 2. Standard BFS loop
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        // Reduce indegree for all neighboring nodes
        for (int neighbour : graph[front]) {
            indegree[neighbour]--;
            // If indegree becomes 0, it means all prerequisites are fulfilled!
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // Optional Check: If ans.size() != nodes, the graph contains a cycle!
    if (ans.size() != nodes) {
        cout << "\nGraph contains a cycle! Topological sort not possible.\n";
        return;
    }

    cout << "\nValid Topological order (BFS / Kahn's): \n";
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;
}

// ------------------- MAIN FUNCTION -------------------
int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    if (!(cin >> nodes >> edges)) return 0;

    vector<vector<int>> graph(nodes);
    vector<int> indegree(nodes, 0);

    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++; // Track incoming edges for Kahn's
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }

    TopologicalSortdfs(graph);
    TopologicalSortbfs(graph, indegree);

    return 0;
}