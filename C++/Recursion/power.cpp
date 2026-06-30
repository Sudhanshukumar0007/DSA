#include<iostream>
using namespace std;
// int power(int m,int n){
//     if(n==0) return 1;
//     return m*power(m,n-1);
// }
int power(int m,int n){
    if(n==0) return 1;
    if(n==1) return m;
    int ans=power(m,n/2);
    if(n%2==0){
        return ans*ans;
    }
    else{
        return m*ans*ans;
    }
}
int main(){
    int m,n;
    cout<<"Enter the number and its power simltaneously: \n";
    cin>>m>>n;
    cout<<power(m,n);
    return 0;
}