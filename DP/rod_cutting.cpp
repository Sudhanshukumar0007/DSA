#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
    int solve(int n,int x,int y,int z){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        int ans1 = 1+solve(n-x,x,y,z);
        int ans2 = 1+solve(n-y,x,y,z);
        int ans3 = 1+solve(n-z,x,y,z);
        return max({ans1,ans2,ans3});
    }
    int solveMemo(int n,int x,int y,int z,vector<int>&dp){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        if(dp[n]!=-1) return dp[n];
        int ans1 = 1 + solveMemo(n-x,x,y,z,dp);
        int ans2 = 1 + solveMemo(n-y,x,y,z,dp);
        int ans3 = 1 + solveMemo(n-z,x,y,z,dp);
        return dp[n] = max({ans1,ans2,ans3});
    }
    int solveTab(int n,int x,int y,int z){
        vector<int>dp(n+1,INT_MIN);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            if(i-x>=0) 
                dp[i] = max(dp[i],dp[i-x]+1);
            if(i-y>=0)
                dp[i] = max(dp[i],dp[i-y]+1);
            if(i-z>=0)
                dp[i] = max(dp[i],dp[i-z]+1);
        }
        if(dp[n]==INT_MIN) return 0;
        return dp[n];
    }
public:
    int maximizeCuts(int n, int x, int y, int z) {
        vector<int>dp(n+1,-1);
        int ans = solveTab(n,x,y,z);
        if(ans<0) return 0;
        return ans;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Rod of length 4, can cut into segments of 2, 1, 1
    // Optimal: Cut into four segments of length 1 (1+1+1+1) -> Max cuts = 4
    int n1 = 4, x1 = 2, y1 = 1, z1 = 1;
    cout << "Test Case 1 Expected: 4 | Got: " << solution.maximizeCuts(n1, x1, y1, z1) << endl;

    // Test Case 2: Rod of length 5, can cut into segments of 5, 3, 2
    // Optimal: Cut into segments of 3 and 2 (3+2) -> Max cuts = 2
    int n2 = 5, x2 = 5, y2 = 3, z2 = 2;
    cout << "Test Case 2 Expected: 2 | Got: " << solution.maximizeCuts(n2, x2, y2, z2) << endl;

    // Test Case 3: Impossible to cut perfectly
    // Rod of length 7, cuts allowed: 5, 3, 5. No combination equals 7.
    int n3 = 7, x3 = 5, y3 = 3, z3 = 5;
    cout << "Test Case 3 Expected: 0 | Got: " << solution.maximizeCuts(n3, x3, y3, z3) << endl;

    return 0;
}