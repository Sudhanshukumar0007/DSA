#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;
char tolower_case(char ch){
    if(ch>='a' && ch<='z') {
        return ch;
    }
    else{
        char temp= ch-'A'+ 'a';
        return temp;
    }
}
bool check_palindrome(char*str,int size){
    int s=0;
    int e=size-1;
    while(s<e){
        if(tolower(str[s])!=tolower(str[e])) return false;
        s++;
        e--;
    }
    return true;
}
int string_length(char*str){
    int i=0;
    while(str[i] !='\0'){
        i++;
    }
    return i;
}
void string_reverse(char*str,int size){
    int i=0,j=size-1;
    while(i<j){
        swap(str[i],str[j]);
        i++;
        j--;
    }
}
int main(){
    char str[20];
    cout<<"Enter a string\n";
    cin>>str;
    cout<<"Reversed string is :\n";
    int size=string_length(str);
    string_reverse(str,size);
    cout<<str<<endl;
    cout<<"String is a plaindrome: \n";
    cout<<check_palindrome(str,size)<<endl;
    cout<<tolower_case('X');
    return 0;
}