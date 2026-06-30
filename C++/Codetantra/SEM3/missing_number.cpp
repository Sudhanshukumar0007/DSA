#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements ofthe array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Given array is \n";
    for(int a:arr){
        cout<<a<<" ";
    }cout<<endl;
    int expected_sum=n*(n+1)/2;
    int actual=0;
    for(int i=0;i<n;i++){
        actual+=arr[i];
    }
    cout<<"The missing number is\n";
    cout<<abs(expected_sum-actual)<<endl;
    return 0 ;
}