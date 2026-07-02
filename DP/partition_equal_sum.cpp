#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool solve(int idx, int target, vector<int>& nums, vector<vector<int>>& memo) {
        if (target == 0) return true; 
        if (idx >= nums.size() || target < 0) return false;

        if (memo[idx][target] != -1) return memo[idx][target];

        bool include = solve(idx + 1, target - nums[idx], nums, memo);
        
        bool exclude = solve(idx + 1, target, nums, memo);

        return memo[idx][target] = include || exclude;
    }
    bool solveMem(vector<int>&nums){
        int total = 0;
        for(int num:nums) total+=num;

        if(total%2!=0) return false;
        int target = total/2;

        vector<bool>dp(target+1,false);
        dp[0] = true;

        for(int num:nums){
            for(int j=target;j>=num;j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[target];
    }
public:
    bool canPartition(vector<int>& nums) {
        // int total_sum = 0;
        // for (int num : nums) {
        //     total_sum += num;
        // }


        // if (total_sum % 2 != 0) return false;

        // int target = total_sum / 2;
        
        // vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        
        return solveMem(nums);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Can be partitioned into [1, 5, 5] and [11]. Both sum to 11.
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test Case 1 (Expect 1): " << sol.canPartition(nums1) << "\n";
    
    // Test Case 2: Cannot be partitioned into equal sum subsets.
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test Case 2 (Expect 0): " << sol.canPartition(nums2) << "\n";
    
    return 0;
}