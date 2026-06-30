#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string>vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
    unordered_map<string,vector<string>>mp;
    vector<string>order;
    for(string s:vec){
        string key=s;
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
    for(auto &grp:groups){
		for(string &s: grp){
			cout<<s<<" ";
		}
		cout<<"\n";
	}
return 0;
}