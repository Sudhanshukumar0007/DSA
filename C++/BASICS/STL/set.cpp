#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>s;
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(2);
    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;
    set<int>::iterator it=s.begin();
    it++;
    s.erase(it);

    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"count 2-->"<<s.count(2)<<endl;
    set<int>::iterator itr=s.find(5);
    for(auto it=itr;it!=s.end();it++){
        cout<<*it<<" ";
    }cout<<endl;
    return 0;
}