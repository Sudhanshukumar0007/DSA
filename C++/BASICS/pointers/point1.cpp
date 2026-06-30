#include<iostream>
using namespace std;
int main(){
    int num=5;
    cout<< num<<endl;
    // Adress of operator &
    cout<<"Adress of num is "<<&num<<endl;
    // Pointers stores adress
    int *ptr = &num;
    cout<<ptr<<endl<<*ptr;
    // Pointer ka type whi hoga jo variable ka type hoga
    return 0;
}