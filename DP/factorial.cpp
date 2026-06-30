#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int>dp(n+1);
    if(n==0){
        cout<<"Factorial of 0 is : 1";
        return 0;
    }
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = i * dp[i-1];
    }
    cout<<"Factorial of "<<n<<" is : "<<dp[n];
    return 0;
}