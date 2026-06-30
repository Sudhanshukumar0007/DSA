/*
Here both Band C class is inheriting the propertis of the class A this means the class A is acting a parent class for both B and C this kind of inheritance is called as heirarchial inheritance
Here D and E class is inheriting the proprties of both B and A thus it is inheriting it in Hierarchial ordersame for class F;
*/
#include<iostream>
using namespace std ;
class A{
    public:
    void func1(){
        cout<<"Inside the function 1"<<endl;
    }
};
class B:public A{
    public:
    void func2(){
        cout<<"Inside of function 2"<<endl;
    }
};
class C: public A{
    public:
    void func3(){
        cout<<"Inside of function 3"<<endl;
    }
};
class D:public B{
    public:
    void func4(){
        cout<<"Inside the function 4"<<endl;
    }
};
class E:public B{
    public:
    void func5(){
        cout<<"Inside the function 5\n";
    }
};
class F:public C{
    public:
    void func6(){
        cout<<"inside the function 6\n";
    }
};
int main(){
    B obj1;
    C obj2;
    D obj3;
    F obj4;
    obj1.func1();
    obj1.func2();
    obj2.func1();
    obj2.func3();
    obj3.func1();
    obj3.func2();
    obj3.func4();
    obj4.func1();
    obj4.func3();
    obj4.func6();
    return 0 ;
}