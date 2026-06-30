v#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> keys(n);
    vector<long long> freq(n); // Changed to long long for safety
    for (int i = 0; i < n; i++) cin >> keys[i];
    for (int i = 0; i < n; i++) cin >> freq[i];

    vector<long long>prefix(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i+1] = prefix[i] + freq[i];
    }
    vector<vector<long long >> dp(n,vector<long long>(n,0));
    for(int len = 2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j = i+len-1;
            dp[i][j] = LLONG_MAX;
            long long weight = prefix[j+1] - prefix[i];
            for(int r=i;r<=j;r++){
                long long left_cost = (r>i) ? dp[i][r-1] : 0;
                long long right_cost = (r<j) ? dp[r+1][j] : 0;
                long long total_cost = left_cost+right_cost  + weight;
                if(total_cost<dp[i][j]){
                    dp[i][j] = total_cost;
                }

            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}