#include<iostream>
using namespace std;
int sum(int a,int b){
    return a+b;
}
int main(){
    int b;
    string sk="Sudhanshu is my name";
    char ch='S';
    bool flag=true;
    float num=152.32565454;
    double num2=152.5556;
    int apples;
    cin>>apples; //Used to take inputs for variables. 
    b=6;
    int c=sum(apples,b);
    cout<<c<<endl; 
    cout<<sk<<endl;
    cout<<ch<<endl;
    cout<<num<<endl;
    cout<<num2<<endl;  
    return 0;
}