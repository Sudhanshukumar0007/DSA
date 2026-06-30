#include<iostream>
using namespace std;
int main(){
    int a;
    int *ptr=&a;
    cin>>*ptr;
    cout<<"value of a:\n"<<a<<endl;
    cout<<"value of the ptr :\n"<<*ptr<<endl;
    cout<<"Adress of the pointer :\n"<<ptr<<endl;
    //Refrence example
    int& myref=a;
    cout<<"value of a\n"<<myref;

    return 0;
}