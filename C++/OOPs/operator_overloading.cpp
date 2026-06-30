/*
operator overloading meaning we can change the function done by the operators according to the need we want like below we have made the + operator to subtract the values of the two operands of object type 




*/





#include<iostream>
using namespace std ;
class B{
    public:
    int a;
    int b;
    public:
    int add(){
        return a+b;
    }
    void operator+ (B &obj){
        int val1=this->a;
        int val2=obj.a;
        cout<<"output "<<val2-val1<<endl;
    }
    void operator() (){
        cout<<"Hello sudhanshu";
    }
};
int main(){
    B obj1,obj2;
    obj1.a=4;
    obj2.a=7;
    obj1 + obj2;
    obj1();

    return 0 ;
}