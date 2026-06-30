#include<iostream>
using namespace std;
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    int *ptr=&arr[0];
    cout<<"Adress of first memory block is "<<arr<<endl;
    cout<<"Adress of first memory block is "<<ptr<<endl;
    cout<<*arr<<endl;
    cout<<*(arr+1)<<endl;
    for(int i=0;i<10;i++){
        cout<<*(arr+i)<<" ";
    }cout<<endl;
    //arr[i]==*(arr+i)
    //i[arr]==*(i+arr)
    cout<<1[arr]<<endl;

    // Using sizeof operator to know the adress differnce 
    int temp[10]={1,2};
    cout<<sizeof(temp)<<endl;
    cout<<sizeof(*temp)<<endl;
    cout<<sizeof(&temp)<<endl;
    int *ptr1=&temp[0];
    cout<<sizeof(ptr1)<<endl;
    cout<<sizeof(*ptr1)<<endl;
    cout<<sizeof(&ptr1)<<endl;
    return 0;
}