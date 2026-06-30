#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>string1(n);
    for(int i=0;i<n;i++){
        cin>>string1[i];
    }
    unordered_map<string,vector<string>>mp;
    vector<string>order;
    for(string s:string1){
        string key = s;
        sort(key.begin(),key.end());
        if(mp.find(key)==mp.end()){
            order.push_back(key);
        }
        mp[key].push_back(s);
    }
    vector<vector<string>>groups;
    for(auto &k:order){
        groups.push_back(mp[k]);
    }
    sort(groups.begin(),groups.end(),[](vector<string>&a,vector<string>&b){
        return a[0]<b[0];
    });
    for(auto &g:groups){
        for(auto &s:g){
            cout<<s<<" ";
        }cout<<endl;
    }
    return 0;
}