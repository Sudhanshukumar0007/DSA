#include<iostream>
using namespace std ;
class A{
    public:
    void sayHello(){
        cout<<"Hello Sudhanshu"<<endl;
    }
    void sayHello(string name){
        cout<<"saying hello twice "<<name;;
    }
};
int main(){
    A obj1;
    obj1.sayHello();
    obj1.sayHello("Sher");
    return 0 ;
}