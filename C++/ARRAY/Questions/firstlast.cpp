#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    int start = -1, end = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            if (start == -1) start = i; // first occurrence
            end = i; // update last occurrence
        }
    }

    cout << start << " " << end << endl;
    return 0;
}
