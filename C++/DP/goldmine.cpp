#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>gold(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>gold[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        dp[i][0] = gold[i][0];
    }
    for(int j=1;j<m;j++){
        for(int i=0;i<n;i++){
            int left = dp[i][j-1];
            int left_up = (i==0) ? 0 : dp[i-1][j-1];
            int left_down = (i==n-1) ? 0 : dp[i+1][j-1];
            dp[i][j] = gold[i][j] + max({left,left_up,left_down});

        }
    }
    int max_gold = 0;
    for(int i=0;i<n;i++){
        max_gold = max(max_gold,dp[i][m-1]);
    }
    cout<<max_gold<<endl;
    return 0;
}