#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>maxi;//Max heap banne ka tarika
    priority_queue<int,vector<int>,greater<int>>mini; //Min heap banane ka tarika
    maxi.push(0);
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(1);
    cout<<"Max heap\n";
    priority_queue<int>temp=maxi;
    while (!temp.empty()){
    cout<<temp.top()<<" ";
    temp.pop();
    }cout<<endl;

    cout<<"MIN heap\n";
    mini.push(0);
    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(1);
     priority_queue<int,vector<int>,greater<int>>tempi=mini;
    while (!tempi.empty()){
    cout<<tempi.top()<<" ";
    tempi.pop();
    }cout<<endl;
    
    return 0;
}