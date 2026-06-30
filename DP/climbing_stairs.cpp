#include<bits/stdc++.h>
using namespace std;
// int countWays(int n){
//     if(n<0) return 0;
//     if(n==0) return 1;

//     return countWays(n-1) + countWays(n-2);
// }

// Using DP

// int countWays(int n,vector<int>&dp){
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return 1;
//     }
//     if(dp[n]!=-1) return dp[n];
//     return dp[n] = countWays(n-1,dp)+countWays(n-2,dp);
// }

int main(){
    int n;
    cout<<"Enter the number of stairs : ";
    //At a time we can climb one or two stairs at max
    cin>>n;
    if(n==0){
        cout<<"No of ways to reach stairs : 1"<<endl;
    }
    vector<int>dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<"No of ways to climb stairs of size n : "<<dp[n]<<endl;


    return 0;
}



//Space efficient Method 
// int main(){
//     int n;
//     cout << "Enter the number of stairs: ";
//     cin >> n;
    
//     if (n == 0 || n == 1) {
//         cout << "No of ways to climb stairs of size n : 1" << endl;
//         return 0;
//     }
    
//     int prev2 = 1; // Represents dp[0]
//     int prev1 = 1; // Represents dp[1]
//     int current;
    
//     for(int i = 2; i <= n; i++){
//         current = prev1 + prev2;
//         prev2 = prev1;
//         prev1 = current;
//     }
    
//     cout << "No of ways to climb stairs of size n : " << current << endl;
//     return 0;
// }