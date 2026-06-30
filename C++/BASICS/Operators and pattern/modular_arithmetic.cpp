#include <iostream>
using namespace std;

// Function to compute (x^n) % m efficiently
int modPower(int x, int n, int m) {
    int result = 1;
    x = x % m;

    while (n > 0) {
        if (n & 1) {
            result = (1LL * result * x) % m;
        }
        x = (1LL * x * x) % m;
        n = n >> 1;
    }

    return result;
}

int main() {
    int x, n, m;
    cout << "Enter the values of x, n, m\n";
    cin >> x >> n >> m;

    int answer = modPower(x, n, m);
    cout << "The answer is\n" << answer;
    return 0;
}
