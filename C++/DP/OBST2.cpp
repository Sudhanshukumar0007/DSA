#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e15;

int main() {
    int n, d;
    if (!(cin >> n >> d)) return 0;

    vector<int> keys(n), freqs(n);
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) cin >> keys[i];
    for (int i = 0; i < n; i++) {
        cin >> freqs[i];
        prefix[i + 1] = prefix[i] + freqs[i];
    }

    // dp[i][j][k] is the min cost for keys from index i to j with max height k
    // Size n+2 to handle boundaries (r-1 or r+1) safely
    vector<vector<vector<long long>>> dp(n + 2, vector<vector<long long>>(n + 2, vector<long long>(d + 1, INF)));

    // Base Case: If there are no keys, the cost is 0 for any depth limit
    for (int k = 0; k <= d; k++) {
        for (int i = 1; i <= n + 1; i++) {
            dp[i][i - 1][k] = 0; 
        }
    }

    // Fill the DP table
    for (int len = 1; len <= n; len++) {            // Subtree length
        for (int i = 1; i <= n - len + 1; i++) {    // Start index
            int j = i + len - 1;                    // End index
            for (int k = 1; k <= d; k++) {          // Depth limit
                
                long long current_sum = prefix[j] - prefix[i - 1];
                
                for (int r = i; r <= j; r++) {      // Try every node as root
                    long long val = dp[i][r - 1][k - 1] + dp[r + 1][j][k - 1] + current_sum;
                    dp[i][j][k] = min(dp[i][j][k], val);
                }
            }
        }
    }

    if (dp[1][n][d] >= INF) {
        cout << "Impossible" << endl;
    } else {
        cout << dp[1][n][d] << endl;
    }

    return 0;
}