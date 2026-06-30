#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>d;
    d.push_back(1);
    d.push_front(2);
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;
    d.pop_front();
    // d.pop_back();
    cout<<"After pop\n";
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;
    d.push_back(10);
    d.push_front(5);
    cout<<"Element at first index-->"<<d.at(1)<<endl;
    cout<<"First element-->"<<d.front()<<endl;
    cout<<"Last element-->"<<d.back()<<endl;
    cout<<"Empty or not-->"<<d.empty()<<endl;
    d.erase(d.begin(),d.begin()+1);
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}