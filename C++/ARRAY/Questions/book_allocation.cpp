#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

// Function to check if a given maxPages is a feasible allocation
bool isFeasible(const vector<int>& pages, int students, int maxPages) {
    int count = 1; // Start with first student
    int total = 0;

    for (int page : pages) {
        if (page > maxPages) return false; // A single book is too large

        if (total + page > maxPages) {
            count++;         // Allocate to next student
            total = page;    // Reset current pages
        } else {
            total += page;
            cout<<total<<endl;
        }
    }

    return count <= students;
}

// Main function to find the minimum possible max pages
int allocateBooks(vector<int>& pages, int students) {
    int n = pages.size();
    if (students > n) return -1; // Not enough books

    int low = *max_element(pages.begin(), pages.end());
    int high = 0;
    for (int page : pages) high += page;

    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(pages, students, mid)) {
            result = mid;
            high = mid - 1; // Try smaller max
        } else {
            low = mid + 1;  // Increase max
        }
    }

    return result;
}

// Driver code
int main() {
    vector<int> pages = {12, 34, 67, 90};
    int students = 2;

    int minMaxPages = allocateBooks(pages, students);
    cout << "Minimum of maximum pages = " << minMaxPages << endl;

    return 0;
}
