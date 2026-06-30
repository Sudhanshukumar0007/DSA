#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"Enter your Age:\n";
    cin>>age;
    if(age<=0){
        cout<<"Pehele janam  toh lele\n";
    }
    else if(age>=18){
        cout<<"Aaaiye aapka intezar tha\n";
    }
    else{
        cout<<"jaake padhai kar le beta\n";
    }
    return 0;
}