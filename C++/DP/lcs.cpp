#include<bits/stdc++.h>
using namespace std;
int main(){
    string x,y,z;
    cin>>x>>y>>z;
    int n1 = x.length();
    int n2 = y.length();
    int n3 = z.length();
    vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
    for(int i=1;i<n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=n3;k++){
                if(x[i-1]==y[j-1] && y[j-1]==z[k-1]){
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] =max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                }
            }
        }
    } 
    cout<<dp[n1][n2][n3]<<endl;
    return 0;
}