#include<bits/stdc++.h>
using namespace std;
bool found = false;
int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    vector<int>res;
    int t = text.size();
    int p = pattern.size();
    for(int i=0;i<=t-p;i++){
        found = true;
        for(int j=0;j<p;j++){
            if(text[i+j]!=pattern[j]){
                found = false;
                break;
            }
        }
        if(found){
                res.push_back(i);
            }
    }
    if(res.size()==0){
        cout<<"Not found"<<endl;
    }
    else{
        for(auto r:res){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 0;
}