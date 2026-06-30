#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>freq;
    for(int a:arr){
        freq[a]++;
    }
    int k;
    cin>>k;
    vector<pair<int,int>>vec(freq.begin(),freq.end());
    sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    });
    for(const auto&pair:vec){
        if(k>0){
            cout<<pair.first<<" ";
            k--;
        }else{
            break;
        }
    }
    return 0;
}