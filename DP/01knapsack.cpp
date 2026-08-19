#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int solve(int idx,int capacity,vector<int>&weight,vector<int>&value){
        if(idx==0){
            if(weight[0]<=capacity){
                return value[0];
            }else{
                return 0;
            }
        }

        int include = 0;
        if(weight[idx]<=capacity){
            include = value[idx] + solve(idx-1,capacity-weight[idx],weight,value);
        }
        int exclude = solve(idx-1,capacity,weight,value);

        int ans = max(include,exclude);
        return ans;
    }
public:
    int knapSack(int capacity, vector<int>& weight, vector<int>& value, int n) {
        int ans = solve(n-1,capacity,weight,value);
        return ans; 
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: The classic scenario
    int capacity1 = 50;
    vector<int> weight1 = {10, 20, 30};
    vector<int> value1 = {60, 100, 120};
    int n1 = weight1.size();
    
    cout << "Test Case 1 (Expect 220): " << sol.knapSack(capacity1, weight1, value1, n1) << "\n";
    
    // Test Case 2: Capacity too small for the highest value item
    int capacity2 = 10;
    vector<int> weight2 = {5, 4, 6, 3};
    vector<int> value2 = {10, 40, 30, 50};
    int n2 = weight2.size();
    
    // Optimal is to pick items with weight 4 (val 40) and 3 (val 50) -> total weight 7, value 90.
    cout << "Test Case 2 (Expect 90): " << sol.knapSack(capacity2, weight2, value2, n2) << "\n";
    
    return 0;
}