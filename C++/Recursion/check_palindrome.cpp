#include<iostream>
using namespace std;
bool check_palindrome(string s,int i,int j){
    if (i >= j) return true;
    if (s[i] != s[j]) return false;
    return check_palindrome(s, i + 1, j - 1);

}
int main(){
    string str;
    cout<<"Enter the string:\n ";
    cin>>str;
    if(check_palindrome(str, 0, str.length()-1))
    cout << "Palindrome";
    else
    cout << "Not a palindrome";
    return 0;
}