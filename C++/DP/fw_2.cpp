#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void floyd(vector<vector<int>>&dist,int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>dist(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            if(i!=j && val==-1){
                dist[i][j] = INF;
            }else{
                dist[i][j] = val;
            }
        }
    }
    floyd(dist,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]>=INF){
                cout<<"INF";
            }else{
                cout<<dist[i][j];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}