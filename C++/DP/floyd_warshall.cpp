#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    int v, e;
    if (!(cin >> v >> e)) return 0;

    vector<vector<long long>> dist(v + 1, vector<long long>(v + 1, INF));

    for (int i = 1; i <= v; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int u, n_v;
        long long w;
        cin >> u >> n_v >> w;
        // Handle multiple edges between same pair: keep the minimum weight
        dist[u][n_v] = min(dist[u][n_v], w);
    }

    // Core Floyd-Warshall DP
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                // Check if paths i->k and k->j exist
                if (dist[i][k] != INF && dist[k][j] != INF) { // Fixed this line
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Optional: Check for negative cycles
    // for (int i = 1; i <= v; i++) {
    //     if (dist[i][i] < 0) {
    //         // cout << "Negative cycle detected!" << endl;
    //     }
    // }

    // Output results
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}