#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string>m;
    m[1]="sudhanshu";
    m[2]="aira";
    m[3]="piyarkifarakwali";
    cout<<"Before erase\n";
    for(auto i:m){
        cout<<i.first<<" ";
        cout<<i.second<<" ";
    }cout<<endl;
    cout<<"finding element-->"<<m.count(2);
    m.erase(2);
    cout<<"After erase\n";
    for(auto i:m){
        cout<<i.first<<" ";
        cout<<i.second<<" ";
    }cout<<endl;
    return 0;
}