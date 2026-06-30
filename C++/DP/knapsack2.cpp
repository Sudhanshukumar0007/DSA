// Knapsack with items limit
#include<bits/stdc++.h>
using namespace std;
struct item{
    int v,w;
};
int main(){
    int n,W,k;
    cin>>n>>W>>k;
    vector<item>items(n);
    for(int i=0;i<n;i++){
        cin>>items[i].w>>items[i].v;
    }
    vector<vector<int>>dp(W+1,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        for(int j=W;j>=items[i].w;j--){
            for(int x=k;x>=1;x--){
                dp[j][x] = max(dp[j][x],items[i].v+dp[j-items[i].w][x-1]);
            }
        }
    }
    int ans = 0;
    for(int x=0;x<=k;x++){
        ans = max(ans,dp[W][x]);
    }
    cout<<ans<<endl;
    return 0;
}