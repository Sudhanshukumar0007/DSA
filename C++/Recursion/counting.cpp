#include<iostream>
using namespace std;
void counting_descending(int num){
    if(num==0) return;
    cout<<num<<" ";
    return counting_descending(num-1);
}
void counting_Ascending(int num){
    if(num==0) return;
    counting_Ascending(num-1);
    cout<<num<<" ";
}
int main(){
    int num;
    cout<<"Enter a number \n";
    cin>>num;
    counting_descending(num);
    cout<<endl;
    counting_Ascending(num);
    return 0;
}