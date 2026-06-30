#include<iostream>
#include<algorithm>
using namespace std;
void Rverse(int i,int j,string &s){
    if(i>j) return ;
    swap(s[i],s[j]);
    return Rverse(i+1,j-1,s);
}

int main(){
    string s="abcde";
    Rverse(0,s.length()-1,s);
    cout<<s;
    return 0;
}