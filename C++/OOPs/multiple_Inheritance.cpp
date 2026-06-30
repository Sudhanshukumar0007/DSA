/*
Inheriting properties from multiple classes like here the class bolnewalakutta inheriting properties from both human and animal.
*/


#include<iostream>
using namespace std ;
class Animal{
    public:
    void bark(){
        cout<<"barking"<<endl;
    }
};
class Human{
    public:
    void speak(){
        cout<<"speaking"<<endl;
    }
};
class bolnewalakutta:public Animal,public Human{

};
int main(){
    bolnewalakutta bhaw1;
    bhaw1.speak();
    bhaw1.bark();
    return 0 ;
}