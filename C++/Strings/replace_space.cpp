#include<iostream>
#include<string>
using namespace std;
string replace_spaces(string &str){
    string result="";
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch==' '){
            result+="@40";
        }else{
            result+=ch;
        }
    }
    return result;
}
int main(){
    string str;
    cout<<"Enter the string\n";
    getline(cin,str);
    string str_updated=replace_spaces(str);
    cout<<str_updated;
    return 0;
}