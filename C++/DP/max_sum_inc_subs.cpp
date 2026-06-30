#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n);
    for(int i=0;i<n;i++){
        dp[i] = arr[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(dp[j]+arr[i]>dp[i]){
                    dp[i] = dp[j] + arr[i];
                }
            }
        }
    }
    int max_sum = 0;
    for(int i=0;i<n;i++){
        max_sum = max(max_sum,dp[i]);
    }
    cout<<max_sum<<endl;
    return 0;
}