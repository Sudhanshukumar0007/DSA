#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    vector<bool> has(26, false);

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        has[toupper(w[0]) - 'A'] = true;
    }

    vector<string> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<bool> formed(m, false);
    int formed_count = 0;

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < m; i++) {
            if (formed[i]) continue;

            bool can_form = true;
            for (char c : a[i]) {
                if (!has[c - 'A']) {
                    can_form = false;
                    break;
                }
            }

            if (can_form) {
                formed[i] = true;
                formed_count++;
                has[a[i][0] - 'A'] = true;
                changed = true;
            }
        }
    }

    if (formed_count == m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    }
    return 0;
}