#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n){
    int cnt=0;
    while(n){
        cnt+=n&1;
        n>>=1;
    }
    return cnt;
}
int main(){
     int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter element of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The given Array is "<<endl;
    for(int num:arr){
        cout<<num<<" ";
    }cout<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            int c1 = countSetBits(arr[j]);
            int c2 = countSetBits(arr[j+1]);
            if(c1<c2){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"The Sorted order according to set bits in non-descending order\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}