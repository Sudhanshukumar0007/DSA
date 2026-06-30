#include<iostream>
#include<array>
using namespace std;
int main(){
    array<int,5>nums={1,2,3,4,5};
    int size=nums.size();
    for(int i=0;i<size;i++){
        cout<<nums[i];
    }cout<<endl;
    cout<<"Element at the index 2-->"<<nums.at(2)<<endl;
    cout<<"Empty or not-->"<<nums.empty()<<endl;
    cout<<"first element-->"<<nums.front()<<endl;
    cout<<"last element-->"<<nums.back()<<endl;
    return 0;
}