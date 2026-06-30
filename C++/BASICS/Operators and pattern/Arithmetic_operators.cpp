#include<iostream>
using namespace std;
int main(){
    int apple,mango,total_cost,distribution;
    cout<<"Enter Numbers of apples"<<endl;
    cin>>apple;
    cout<<"Enter number of mangoes\n";
    cin>>mango;
    cout<<"total numbers of fruits\n";
    cout<<apple+mango<<endl;
    cout<<"Distribution between apple and mango"<<endl<<apple-mango<<endl;
    cout<<"Total cost\n";//Each mango and apple cost 5 rupees
    cout<<apple*5+mango*5<<endl;
    cout<<"Distribution among 5 equally\n";
    cout<<apple/5<<endl<<mango/5<<endl;
    cout<<apple%mango<<endl;//Modulus operator
    //Increment and decrement operator
    cout<<mango++<<endl;
    cout<<++mango<<endl;
    cout<<--apple<<endl;
    cout<<apple--<<endl;
    return 0;
}