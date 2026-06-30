#include<iostream>
using namespace std ;
class Animal{
    public:
    void speaking(){
        cout<<"Speaking";
    }
};
class dog:public Animal{
    public:
    void speaking(){
        cout<<"barking--Bhaw Bhaw";
    }
};
int main(){
    dog vodafone;
    vodafone.speaking();
    return 0 ;
}