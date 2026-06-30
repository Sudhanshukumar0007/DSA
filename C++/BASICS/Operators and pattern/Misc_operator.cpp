#include<iostream>
using namespace std;
int main(){
    int a=4;
    char b='s';
    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
    int bada=10,chota=5;
    bada<chota?cout<<"bada":cout<<"chota";
    bool p=false;
    bool q=false;
    bool r=true;
    cout<<(p==q==r);
    return 0;
}