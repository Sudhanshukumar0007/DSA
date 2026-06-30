#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string>q;
    q.push("sudhanshu");
    q.push("Aira");
    q.push("piyarfarakwali");
    cout<<"First element-->"<<q.front()<<endl;
    cout<<"Last element -->"<<q.back()<<endl;
    queue<string>temp=q;
    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }cout<<endl;
    cout<<"size of the queue "<<q.size()<<endl;
    return 0;
}