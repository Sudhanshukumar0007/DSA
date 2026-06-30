#include<iostream>
using namespace std;
int CountDistinctWayToClimbStair(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    return CountDistinctWayToClimbStair(n-1)+CountDistinctWayToClimbStair(n-2);
}
int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    cout<<CountDistinctWayToClimbStair(n);
    return 0;
}