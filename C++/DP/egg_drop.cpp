#include <iostream>
#include <vector>

using namespace std;

int superEggDrop(int e, int f) {
    // dp[i] represents the max floors we can check with 'i' eggs
    vector<int> dp(e + 1, 0);
    int moves = 0;
    
    while (dp[e] < f) {
        moves++;
        // Iterate backwards to use values from the previous 'moves'
        for (int i = e; i > 0; i--) {
            dp[i] = dp[i] + dp[i - 1] + 1;
        }
    }
    return moves;
}

int main() {
    int e, f;
    if (cin >> e >> f) {
        cout << superEggDrop(e, f) << endl;
    }
    return 0;
}