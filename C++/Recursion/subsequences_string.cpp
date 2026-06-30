#include <iostream>
#include <vector>
using namespace std;

void solve(string s, vector<vector<string>>& ans, vector<string> output, int index) {
    // Base case
    if (index == s.length()) {
        ans.push_back(output);
        return;
    }

    // Exclude current character
    solve(s, ans, output, index + 1);

    // Include current character
    string element(1, s[index]); // Convert char to string
    output.push_back(element);
    solve(s, ans, output, index + 1);
}

vector<vector<string>> subsequences(string s) {
    vector<vector<string>> ans;
    vector<string> output;
    int index = 0;
    solve(s, ans, output, index);
    return ans;
}

int main() {
    string s = "abc";
    vector<vector<string>> result = subsequences(s);

    cout << "Subsequences:\n";
    for (auto subset : result) {
        cout << "{ ";
        for (auto str : subset) {
            cout << str << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
