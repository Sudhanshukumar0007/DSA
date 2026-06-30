#include<iostream>
using namespace std;
class Hero{
    private: 
    int health;
     public:  
    char level;
    void print(){
        cout<<"level is : "<<level<<endl;
    }
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int h){
        health=h;
    }
    void setLevel(char L){
        level=L;
    }
};
int main(){
    Hero  h1;
    cout<<"Health is :"<<h1.getHealth()<<endl;
    h1.setHealth(50);
    // h1.health=50;
    h1.level='A';
    cout<<"Health is : "<<h1.getHealth()<<endl;
    cout<<"Level is : "<<h1.level<<endl;
    cout<<"Size of the class Hero is : "<<sizeof(h1)<<endl;
    return 0;
}