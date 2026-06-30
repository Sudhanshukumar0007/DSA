#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,targetSum;
    cin>>n>>targetSum;
    vector<int>coin(n);
    vector<int>dp(targetSum+1,0);
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=coin[i];j<=targetSum;j++){
            dp[j] += dp[j-coin[i]];
        }
    }
    cout<<dp[targetSum]<<endl;
    return 0;
}