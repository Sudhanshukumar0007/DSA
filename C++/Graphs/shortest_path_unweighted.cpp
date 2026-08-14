// we are going to find the shortest path in an unweighted graph using bfs ,parent and visited array firstly finding  the parents of node then traversing back to source from destination will give us the shortest path

#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>&graph,vector<bool>&visited,vector<int>&parent,int startNode){
    queue<int>q;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int neighbour:graph[curr]){
            if(!visited[neighbour]){
                parent[neighbour] = curr;
                visited[neighbour] = true;
                q.push(neighbour); 
            }
        }
    }
}
int shortestPath(vector<vector<int>>&graph,int source,int dest){
    int nodes = graph.size();
    vector<int>parent(nodes,-1);
    vector<bool>visited(nodes,false);
    bfs(graph,visited,parent,source);
    vector<int>ans;
    if(!visited[dest]){
        cout<<"No path exist in between source and destination.\n";
        return -1;
    }
    vector<int>path;
    for(int curr = dest;curr!=-1;curr = parent[curr]){
        path.push_back(curr);
    }
    reverse(path.begin(),path.end());
    cout<<"Path:\n";
    for(int node:path){
        cout<<node<<" ";
    }
    cout<<endl;
    return path.size()-1;
}
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
    int src,dest;
    cout<<"Enter source and destination \n";
    cin>>src>>dest;
    int ans = shortestPath(graph,src,dest);
    cout<<"Length of the shortest path from source to destination: \n";
    cout<<ans<<endl;
    return 0;
}