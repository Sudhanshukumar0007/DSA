#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,w;
    cin>>n>>w;
    vector<int>values(n),weights(n);
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    vector<int>dp(w+1,0);
    for(int i=0;i<n;i++){
        for(int j=w;j>=weights[i];j--){
            dp[j] = max(dp[j],values[i]+dp[j-weights[i]]);
        }
    }
    cout<<dp[n];
    return 0;
}