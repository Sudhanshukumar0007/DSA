#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
    int solve(vector<int>&coins,int amount){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        return mini;
    }
     int solveMem(vector<int>&coins,int amount,vector<int>&dp){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        dp[amount] = mini;
        return mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int>dp(amount+1,INT_MAX);
    //   int ans = solveMem(coins,amount,dp);
    //   if(ans==INT_MAX) return -1;
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
            }
        }
        if(dp[amount]==INT_MAX) return -1;
      return dp[amount];
    }
};

int main() {
    Solution solver;

    // --- Test Case 1 ---
    // Expected Output: 3 (11 = 5 + 5 + 1)
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test Case 1 - Expected: 3, Got: " << solver.coinChange(coins1, amount1) << endl;

    // --- Test Case 2 ---
    // Expected Output: -1 (You cannot make 3 out of a 2-unit coin)
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 - Expected: -1, Got: " << solver.coinChange(coins2, amount2) << endl;

    // --- Test Case 3 ---
    // Expected Output: 0 (0 amount needs 0 coins)
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test Case 3 - Expected: 0, Got: " << solver.coinChange(coins3, amount3) << endl;

    return 0;
}