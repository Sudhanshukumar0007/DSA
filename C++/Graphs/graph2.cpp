#include <iostream>
#include <vector>
#include<queue>
#include<unordered_map>
using namespace std;
bool isCyclicdfs(const vector<vector<int>>& graph, vector<bool>& visited, int u, int parent) {
    visited[u] = true;
    
    for (int neighbour : graph[u]) {
        if (!visited[neighbour]) {
            if (isCyclicdfs(graph, visited, neighbour, u)) {
                return true;
            }
        } 
        else if (neighbour != parent) {
            return true;
        }
    }
    
    return false;
}
bool isCyclicbfs(const vector<vector<int>>& graph, vector<bool>& visited, int startNode) {
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;
    parent[startNode] = -1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int neighbour : graph[front]) {
            if (visited[neighbour] && neighbour != parent[front]) {
                return true;
            }
            else if (!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }
    return false;
}

void iscycle(const vector<vector<int>>& graph, int nodes) {
    vector<bool> visited(nodes, false);
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            // if (isCyclicbfs(graph, visited, i)) {
            if (isCyclicdfs(graph, visited, i,-1)) {
                cout << "Cycle Present: Yes\n";
                return;
            }
        }
    }
    cout << "Cycle Present: No\n";
}
void bfs(const vector<vector<int>>&graph,vector<bool>&visited,int startNode,vector<int>&ans){
    queue<int>q;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int front  = q.front();
        q.pop();

        ans.push_back(front);
        for(int neighbour:graph[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int currentNode, vector<int>& ans) {
    visited[currentNode] = true;
    ans.push_back(currentNode);

    for (int neighbour : graph[currentNode]) {
        if (!visited[neighbour]) {
            dfs(graph, visited, neighbour, ans); 
        }
    }
}

vector<int> dfsDisconnected(const vector<vector<int>>& graph, int nodes) {
    vector<bool> visited(nodes, false);
    vector<int> ans;

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, ans);
        }
    }

    return ans; 
}

vector<int> bfsDisconnected(const vector<vector<int>>& graph, int nodes) {
    vector<bool> visited(nodes, false);
    vector<int> ans;

    // Loop through every node to ensure disconnected components are visited
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            bfs(graph, visited, i, ans);
        }
    }

    return ans;
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

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }

    vector<int> ans = bfsDisconnected(graph, nodes);

    cout << "\nBFS Traversal of Disconnected Graph:\n";
    for (int node : ans) {
        cout << node << " ";
    }
    cout << "\n";

    vector<int> ans2 = dfsDisconnected(graph, nodes); 
    
    cout << "\nDFS Traversal of Disconnected Graph:\n";
    for (int node : ans2) {
        cout << node << " ";
    }
    cout << "\n";

    iscycle(graph,nodes);
    return 0;
}