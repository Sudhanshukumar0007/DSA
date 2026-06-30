#include<iostream>
using namespace std ;
class Animal{
    public:
        string name;
        int existance;
};
class dog:public Animal{
    public:
        string breed;
        int age;
};
int main(){
    dog street;
    street.name="jangli";
    street.existance=100000;
    street.breed="kya pata";
    street.age=20;
    cout<<street.name<<endl;
    cout<<street.existance<<endl;
    cout<<street.breed<<endl;
    cout<<street.age<<endl;
    return 0 ;
}