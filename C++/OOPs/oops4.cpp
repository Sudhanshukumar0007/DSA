#include<iostream>
using namespace std ;
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
    //Static allocation
    Hero a;
    // Dynamically allocating the class hero;
    Hero *b=new Hero;
    (*b).level='A';
    (*b).setHealth(70);
    cout<<"Health is : "<<(*b).getHealth()<<endl;
    cout<<"Level is : "<<(*b).getLevel()<<endl;

    cout<<"Health is : "<<b->getHealth()<<endl;
    cout<<"Level is : "<<b->getLevel()<<endl;

    return 0 ;
}