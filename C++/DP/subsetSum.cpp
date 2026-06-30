#include <iostream>
#include <vector>

using namespace std;

int n, target;
vector<int> arr;
vector<vector<int>> allSubsets;
int maxSize = -1;

void findSubset(int idx, int curr_sum, vector<int>& currentSubset) {
    // Check if target is reached
    if (curr_sum == target) {
        int currentSize = currentSubset.size();
        if (currentSize > maxSize) {
            maxSize = currentSize;
            allSubsets.clear(); // Found a bigger subset, discard smaller ones
            allSubsets.push_back(currentSubset);
        } else if (currentSize == maxSize) {
            allSubsets.push_back(currentSubset);
        }
        return; 
    }

    // Base cases for stopping
    if (idx >= n || curr_sum > target) {
        return;
    }

    // Choice 1: Include arr[idx]
    currentSubset.push_back(arr[idx]);
    findSubset(idx + 1, curr_sum + arr[idx], currentSubset);
    
    // Choice 2: Exclude arr[idx] (Backtrack)
    currentSubset.pop_back();
    findSubset(idx + 1, curr_sum, currentSubset);
}

int main() {
    if (!(cin >> n >> target)) return 0;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> currentSubset;
    findSubset(0, 0, currentSubset);

    if (allSubsets.empty()) {
        cout << "No subset found" << endl;
    } else {
        for (const auto& subset : allSubsets) {
            cout << "[";
            for (int i = 0; i < subset.size(); i++) {
                cout << subset[i] << (i == subset.size() - 1 ? "" : " ");
            }
            cout << "]" << endl;
        }
    }

    return 0;
}