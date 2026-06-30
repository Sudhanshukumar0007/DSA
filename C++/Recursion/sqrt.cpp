#include<iostream>
using namespace std;
int square_root(int num) {
    if (num < 2) return num; // Edge cases for 0 and 1

    int low = 1, high = num, ans = 1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid == num) {
            return mid;
        } else if (mid * mid < num) {
            ans = mid;      // store the floor of sqrt
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int main(){
    int num;
    cout<<"Enter the number :\n";
    cin>>num;
    cout<<"Square root of the given number is: \n";
    cout<<square_root(num);
    return 0;
}