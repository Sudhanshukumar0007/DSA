// We will be using disjoint sets to find the different components of graph and then merge it 

#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};
int findParent(vector<int>&parent,int u){
    if(parent[u]==u) return u;

    return parent[u] = findParent(parent,parent[u]);
}
bool unionSet(vector<int>&parent,vector<int>&rank,int u,int v){
    int rootU = findParent(parent,u);
    int rootV = findParent(parent,v);
    if(rootU==rootV) return false;
    if(rank[rootU]<rank[rootV]){
        parent[rootU] = rootV;
    }else if(rank[rootV]<rank[rootU]){
        parent[rootV] = rootU;
    }else{
        parent[rootV] = rootU;
        rank[rootU]++;
    }
    return true;
}

int main() {
    int nodes, numEdges;
    cout << "Enter number of nodes and edges: ";
    if (!(cin >> nodes >> numEdges)) return 0;
    vector<Edge>edges(numEdges);

    cout << "Enter " << numEdges << " edges (u v w):\n";
    for (int i = 0; i < numEdges; i++) {
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){
        return a.w<b.w;
    });
    vector<int>rank(nodes+1,0);
    vector<int>parent(nodes+1);
    for(int i=1;i<=nodes;i++){
        parent[i] = i;
    }
    int total_weight = 0;
    vector<Edge>mst;
    for(auto &edge:edges){
        if(unionSet(parent,rank,edge.u,edge.v)){
            total_weight+=edge.w;
            mst.push_back(edge);
        }
    }
    cout << "\nEdges in MST:\n";
    for (const auto& e : mst) {
        cout << e.u << " - " << e.v << " (weight: " << e.w << ")\n";
    }
    cout << "Total Minimum Weight: " << total_weight << "\n";
    return 0;
}