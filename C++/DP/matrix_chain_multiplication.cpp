#include<bits/stdc++.h>
using namespace std;
int MatrixChainMultiplication(vector<int>&arr,int n){
    int numMat = n-1;
    vector<vector<long long >>dp(numMat+1,vector<long long>(numMat+1,0));
    for(int l=2;l<=n;l++){
        for(int i=1;i<=numMat-l+1;i++){
            int j = i+l-1;
            dp[i][j] = LLONG_MAX;
            for(int k=i;k<j;k++){
                long long current_cost = dp[i][k] + dp[k+1][j] + (long long ) arr[i-1] * arr[k] * arr[j];
                if(current_cost<dp[i][j]){
                    dp[i][j] = current_cost;
                }
            }
        }
    }
    return dp[1][numMat];
}
int main(){
    int n;
    cin>>n;
    vector<int>m(n);
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    cout<<MatrixChainMultiplication(m,n);
    return 0;
}