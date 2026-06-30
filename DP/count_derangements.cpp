#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDerangement(int n) {
        int MOD = 1e9 + 7;
       
    }
};

int main() {
    Solution solution;

    // Test Case 1: 2 elements
    // Array: [1, 2] -> Derangements: [2, 1] 
    cout << "Test Case 1 (n=2) Expected: 1 | Got: " << solution.findDerangement(2) << endl;

    // Test Case 2: 3 elements
    // Array: [1, 2, 3] -> Derangements: [2, 3, 1], [3, 1, 2] 
    cout << "Test Case 2 (n=3) Expected: 2 | Got: " << solution.findDerangement(3) << endl;

    // Test Case 3: 4 elements
    // Array: [1, 2, 3, 4] -> 9 possible derangements
    cout << "Test Case 3 (n=4) Expected: 9 | Got: " << solution.findDerangement(4) << endl;

    // Test Case 4: Larger number to test MOD logic
    cout << "Test Case 4 (n=10) Expected: 1334961 | Got: " << solution.findDerangement(10) << endl;

    return 0;
}