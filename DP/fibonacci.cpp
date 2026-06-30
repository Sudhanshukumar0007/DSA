#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    // 1. Handle the edge case where n is 0
    if (n == 0) {
        cout << " Nth term of the fibonacci series is : 0" << endl;
        return 0;
    }

    // 2. Size needs to be n + 1 to safely access dp[n]
    // vector<int> dp(n + 1);
    
    // dp[0] = 0;
    // dp[1] = 1;
    
    // // 3. Start the loop from index 2 and go up to n
    // for (int i = 2; i <= n; i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    
    // cout << " Nth term of the fibonacci series is : " << dp[n] << endl;
    
    // If we use space optimisation then 
    int prev1 = 1;
    int prev2 = 0;
    for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<"Nth fibonacci number : "<<prev1<<endl;
    return 0;
}