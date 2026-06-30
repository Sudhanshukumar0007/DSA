#include<iostream>
using namespace std;
int string_length(char*str){
    int i=0;
    while(str[i] !='\0'){
        i++;
    }
    return i;
}
int main(){
    char str[20];
    cout<<"Enter the stting \n";
    cin>>str;
    cout<<"Length of the  string is: ";
    cout<<string_length(str);
    return 0;
}