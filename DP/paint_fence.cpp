#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int solve(int n,int k,vector<int>&dp){
        if(n==1) return k;
        if(n==2) return k+k*(k-1);
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(k-1)*(solve(n-2,k) + solve(n-1,k)); 
    }
public:
    int numWays(int n, int k) {
       vector<int>dp(n+1,-1);
       return solve(n,k,dp);
    }
};

int main() {
    Solution solution;

    // Test Case 1: 3 posts, 2 colors
    // Expected: 6 (The valid ways are: 121, 122, 112, 212, 221, 211)
    cout << "Test Case 1 Expected: 6  | Got: " << solution.numWays(3, 2) << endl;

    // Test Case 2: 1 post, 1 color
    cout << "Test Case 2 Expected: 1  | Got: " << solution.numWays(1, 1) << endl;

    // Test Case 3: 7 posts, 2 colors
    cout << "Test Case 3 Expected: 42 | Got: " << solution.numWays(7, 2) << endl;

    return 0;
}