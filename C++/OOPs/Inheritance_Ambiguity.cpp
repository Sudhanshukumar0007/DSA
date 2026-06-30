/*
Here the class c is inheriting the properties of both the class A and B and inside those classes they have a function having same name func creating an ambiguity when we call an object of class C with the func so to clear that ambiguity we use scope resolution operator by which we can tell which function to use
Scope resoultion operator (::)
*/




#include<iostream>
using namespace std ;
class A{
    public:
    void func(){
        cout<<"This is function of class A"<<endl;
    }
};
class B{
    public:
    void func(){
        cout<<"this is function of class B"<<endl;
    }
};
class c:public A,public B{

};
int main(){
  c object;
  object.A ::func();  
  object.B :: func();
    return 0 ;
}