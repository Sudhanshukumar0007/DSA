#include<iostream>
using namespace std;
int main(){
    int a, b;
    a=6;
    b=5;
    int Sum=a+b;
    int diff=a-b;
    int multiply=a*b;
    cout<<(Sum>diff && Sum>multiply)<<endl;
    cout<<(Sum>diff || Sum>multiply)<<endl;
    cout<<(!Sum>diff)<<endl;
    // Bitwise operators
    cout<<(~a)<<endl; //compliment Compliments the number in binary form
    cout<<(a<<1)<<endl;//Left shift Multiplies number by 2
    cout<<(a>>1)<<endl;//Right shift Divides number by 2
    cout<<(a|b)<<endl;//Bitwise or 
    cout<<(a&b)<<endl;//Bitwise and 
    cout<<(a^b)<<endl;//exclusive Xor

    return 0;
}