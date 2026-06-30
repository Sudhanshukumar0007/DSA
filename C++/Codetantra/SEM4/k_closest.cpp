#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k,c;
    cin>>k>>c;
    int pos = lower_bound(arr.begin(),arr.end(),c) - arr.begin();
    int left = pos-1;
    int right = pos;
    vector<int>result;
    while(k--){
        if(left<0){
            result.push_back(arr[right++]);
        }
        else if(right>=n){
            result.push_back(arr[left--]);
        }
        else if(abs(arr[left]-c)<=abs(arr[right]-c)){
            result.push_back(arr[left--]);
        }
        else{
            result.push_back(arr[right++]);
        }
    }
    sort(result.begin(),result.end());
    for(int i:result){
        cout<<i<<" ";
    }
}