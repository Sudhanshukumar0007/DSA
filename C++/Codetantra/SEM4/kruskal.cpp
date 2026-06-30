#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u,v,w;
};
vector<int>parent,rankv;
int findParent(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}
void unionSet(int a,int b){
    a = findParent(a);
    b = findParent(b);
    if(a!=b){
        if(rankv[a]<rankv[b]){
            swap(a,b);
        }
        parent[b] = a;
        if(rankv[a]==rankv[b]){
            rankv[a]++;
        }
    }
}
int main(){
    int V,E;
    cin>>V;
    cin>>E;
    vector<Edge>edges(E);
    for(int i=0;i<E;i++){
       cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    sort(edges.begin(),edges.end(),[](Edge a,Edge b){
        return a.w<b.w;
    });
    parent.resize(V);
    rankv.resize(V,0);
    for(int i=0;i<V;i++){
        parent[i] = i;
    }
    int total_cost = 0;
    int edges_used = 0;
    for(int i=0;i<E;i++){
        if(findParent(edges[i].u)!=findParent(edges[i].v)){
           cout<<"Edge: "<<edges[i].u<<" - "<<edges[i].v<<" with weight "<<edges[i].w<<endl;
            total_cost+=edges[i].w;
            unionSet(edges[i].u,edges[i].v);
            edges_used++;
            if(edges_used==V-1){
                break;
            }
        }
    }
    cout<<total_cost<<endl;
    return 0;
}