#include<iostream>
using namespace std;
void SayDigit(int num,string arr[]){
    if (num==0) return ;
    int digit=num%10;
    num=num/10;
    SayDigit(num,arr);
    cout<<arr[digit]<<" ";
}
int main(){
    int num;
    cout<<"Enter the number\n";
    cin>>num;
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    SayDigit(num,arr);
    return 0;
} 