#include<bits/stdc++.h>
using namespace std;
int main(){
    int V;
    cin>>V;
    vector<vector<int>>graph(V,vector<int>(V));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
    vector<int>key(V,INT_MAX);
    vector<bool>mstSet(V,false);
    key[0] = 0;
    int totalcost = 0;
    for(int count = 0;count<V;count++){
        int minkey = INT_MAX;
        int u;
        for(int v=0;v<V;v++){
            if(!mstSet[v] && key[v]<minkey){
                minkey = key[v];
                u = v;
            }
        }
        mstSet[u] = true;
        totalcost+=key[u];
        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 && !mstSet[v] &&graph[u][v]<key[v]){
                key[v] = graph[u][v];
            }
        }
    }
    cout<<totalcost<<endl;
}