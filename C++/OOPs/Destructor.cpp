#include<iostream>
#include<cstring>
using namespace std ;
class Hero{
    private: 
    int health;
     public:  
     char*name;
    char level;
    static int timeToComplete;

    // Unparameterised constructor
    Hero(){
        cout<<"Simple Constructor called\n";
        name=new char[100];
    }
    
    // Parameterised Constructor
    Hero(int health){
        cout<<"this->"<<this<<endl;
        this->health=health;
    }
     Hero(int health,char level){
        this->level=level;
        this->health=health;
    }

    // Copy constructor
    Hero(Hero &temp){
        char*ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name); 
        this->name=ch;
        this->health=temp.health;
        this->level=temp.level;
    }

    void print(){
        cout<<endl;
        cout<<"[ Name:"<<this->name<<" ,";
        cout<<"Health : "<<this->health<<" ,";
        cout<<"level : "<<this->level<<" ]";
        cout<<endl;
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
    void setName(char name[]){
        strcpy(this->name,name);
    }
    //Destructor
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};
int Hero::timeToComplete=5;
int main(){
    cout<<Hero::timeToComplete<<endl;

    // // static
    // Hero a;
    // // Dynamic
    // Hero *b=new Hero;
    // return 0 ;
}