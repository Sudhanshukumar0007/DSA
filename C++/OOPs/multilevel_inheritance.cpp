/*
Here the child class Male inherited properties from human and the child class of male boy inherited properties of class male in this way the properties of class human is inherited by the class boy this type of inheritance us calledmultilevel inheritance.
*/
#include<iostream>
using namespace std ;
class Human{
    public:
        int height;
        int weight;
        int age;
    public:
        int setAge(int age){
            return this->age=age;
        }
        int setWeight(int w){
            this->weight=w;
        }
        int setHeight(int w){
            this->height=w;
        }
};
class Male:public Human{
    public:
        string name;
    void sleep(){
        cout<<"Male is sleeping\n";
    }
};
class Boy:public Male{

};
int main(){
    Boy sudhanshu;
    sudhanshu.setAge(2);
    cout<<sudhanshu.age<<endl;
    return 0 ;
}