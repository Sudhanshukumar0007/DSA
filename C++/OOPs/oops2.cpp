#include<iostream>
using namespace std;
class Hero{
    public:            //BY default access modifiers are private means 
    // Public SCOPE Global;
    int health;
    private:    //(SCOPE Inside the class only )
    char level;
    void print(){
        cout<<"level is : "<<level<<endl;
    }
};
int main(){
    Hero  h1;
    //Now we want to print the properties of class Hero;
    //Using dot (".") operator
    cout<<"Health is : "<<h1.health<<endl;
    // cout<<"Level is : "<<h1.level<<endl;
    return 0;
}