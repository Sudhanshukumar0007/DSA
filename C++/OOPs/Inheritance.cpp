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
int main(){
    Male first;
    cout<<first.age<<endl;
    cout<<first.height<<endl;
    cout<<first.weight<<endl;
    first.sleep();
    first.setWeight(63);
    first.setHeight(163);
    first.setAge(19);
    cout<<first.age<<endl;
    cout<<first.height<<endl;
    cout<<first.weight<<endl;
    return 0 ;
}