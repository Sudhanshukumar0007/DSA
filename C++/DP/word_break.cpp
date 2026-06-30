#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>dict(n);
    for(int i=0;i<n;i++){
        cin>>dict[i];
    }
    string s;
    cin>>s;
    string curr="";
    int i = 0;
    map<string,int>mp;
    for(auto d:dict){
        mp[d]++;
    }
    while(i<s.size()){
        curr.push_back(s[i]);
        if(mp.find(curr)!=mp.end()){
            curr="";
        }
        i++;
    }
    if(curr.size()==0){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}