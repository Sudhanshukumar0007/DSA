#include<iostream>
using namespace std;
//In this way it takes a lot of time of very big n 
bool IsPrime(int n) {
    if (n <= 1) return false;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) count++;
    }
    return count == 2;  // only divisible by 1 and n
}

int main(){
    int n;
    cout<<"Enter a number\n";
    cin>>n;
    if(IsPrime(n)){
        cout<<"The given number is prime\n";
    }
    else{
        cout<<"Given number is not a prime\n";
    }
    return 0;
}