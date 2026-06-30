#include<iostream>
using namespace std;
int main(){
    int choice,num1,num2,result;
    cout<<"Enter two numbers:\n";
    cin>>num1>>num2;
    cout<<"Enter your choice: 1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Remainder\n";
    cin>>choice;
    switch(choice){
        case 1:result=num1+num2;
        break;
        case 2:result=num1-num2;
        break;
        case 3:result=num1*num2;
        break;
        case 4:if(num2==0){
            cout<<"Cannot divide by zero";
        }
        else{
            result=num1/num2;
        }
        break;
        case 5:result=num1%num2;
        default:cout<<"Enter a valid choice.\n";
    }
    if(result){
        cout<<"The result of the operation choosen is "<<result;
    }
    return 0;
}