#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;

    // Fixed Top-Down Memoization
    int solve(int n, vector<int>& dp) {
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        // Use long long to prevent overflow before modulo
        long long a = solve(n - 1, dp) % MOD;
        long long b = solve(n - 2, dp) % MOD;
        
        long long sum = (a + b) % MOD;
        long long ans = ((n - 1) * sum) % MOD;
        
        return dp[n] = ans;
    }
    
    // Fixed Bottom-Up Tabulation
    int solveTab(int n) {
        // Handle edge case instantly to prevent segfaults
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i = 3; i <= n; i++) {
            // Apply MOD at every single math operation
            long long sum = (dp[i - 1] + dp[i - 2]) % MOD;
            long long ans = ((i - 1) * sum) % MOD;
            dp[i] = ans;
        }
        
        return dp[n];
    }
    
public:
    int countDerangements(int n) {
        // Both approaches now work perfectly!
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);
        
        return solveTab(n);
    }
};

int main() {
    Solution solution;

    cout << "Test Case 1 (n=1) Expected: 0  | Got: " << solution.countDerangements(1) << endl;
    cout << "Test Case 2 (n=2) Expected: 1  | Got: " << solution.countDerangements(2) << endl;
    cout << "Test Case 3 (n=3) Expected: 2  | Got: " << solution.countDerangements(3) << endl;
    cout << "Test Case 4 (n=4) Expected: 9  | Got: " << solution.countDerangements(4) << endl;
    cout << "Test Case 5 (n=5) Expected: 44 | Got: " << solution.countDerangements(5) << endl;

    return 0;
}