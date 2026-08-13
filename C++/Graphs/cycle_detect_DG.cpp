#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>&graph,vector<bool>&visited,vector<bool>&dfsvisited,int u){
    visited[u] = true;
    dfsvisited[u] = true;
    for(int neighbour:graph[u]){
        if(dfsvisited[neighbour]){
            return true;
        }else if(!visited[neighbour]){
            if(dfs(graph,visited,dfsvisited,neighbour)){
                return true;
            }
            
        }
    }
    dfsvisited[u] = false;
    return false;
}
void isCycle(vector<vector<int>>&graph){
    int nodes = graph.size();
    bool ans = false;
    vector<bool>visited(nodes,false);
    vector<bool>dfsvisited(nodes,false);
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            ans = dfs(graph,visited,dfsvisited,i);
            if(ans==true){
                break;
            }
        }
    }
if (ans) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
    isCycle(graph);
    return 0;
}