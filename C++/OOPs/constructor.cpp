#include<iostream>
#include<cstring>
using namespace std;
class Hero{
    private: 
    int health;
     public:  
     char*name;
    char level;

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
};
int main(){

    // Deep copy shallow copy
    Hero hero1;
    hero1.setHealth(50);
    hero1.setLevel('C');
    char name[]="Sudhanshu";
    hero1.setName(name);
    hero1.print();

    // Default copy constructor does the shallow copy
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0]='s';
    hero1.print();

    hero2.print();
    //Copy using assignment operator
    hero1=hero2;
    hero1.print();
    hero2.print();
















    //using copy constructor
    // Hero sk(70,'c');
    // Hero skg(sk);
    // skg.print();

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //Object created statically and the constructor gets called automatically
    // Hero  h1(50,'A');
    // h1.print();
    // cout<<"Adresss of h1: "<<&h1<<endl;
    // cout<<"Helath is :"<<h1.getHealth()<<endl;
    // cout<<"Level is :" <<h1.getLevel()<<endl;
    // //dynamically
    // Hero *h2=new Hero(10,'B');
    // h2->print();
    // cout<<"Health is : "<< h2->getHealth();
    return 0;
}