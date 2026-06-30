#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int solve(vector<int>&nums,int x){
        if(x>=nums.size()) return 0;
        int pick = nums[x] + solve(nums,x+2);
        int notpick = 0 + solve(nums,x+1);
        return max(pick,notpick);
    }
    int solveMemo(vector<int>&nums,int x,vector<int>&dp){
        if(x>=nums.size()) return 0;
        if(dp[x]!=-1) return dp[x];
        int pick = nums[x] + solveMemo(nums,x+2,dp);
        int notpick = 0 + solveMemo(nums,x+1,dp);
        return dp[x] = max(pick,notpick);
    }
    int solveTab(vector<int>nums,int x,vector<int>&dp){

    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solveMemo(nums,0,dp);
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Standard alternating elements
    vector<int> nums1 = {1, 2, 3, 1}; 
    cout << "Test Case 1 Expected: 4 | Got: " << solution.rob(nums1) << endl;

    // Test Case 2: Choosing the edge elements
    vector<int> nums2 = {2, 7, 9, 3, 1}; 
    cout << "Test Case 2 Expected: 12 | Got: " << solution.rob(nums2) << endl;

    return 0;
}