#include<iostream>
using namespace std;
int main(){
    for(int i=0;i<50;i++){
        if(i%3!=0){
            cout<<i<<endl;
        }
        else{
            continue;
        }
    }
    return 0;
}