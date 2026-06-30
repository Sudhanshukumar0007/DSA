#include<iostream>
#include<string>
using namespace std;
string removeDuplicates(string s) {
    string result = "";
    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back(); 
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main(){
    string s;
    cout<<"Enter a string\n";
    cin>>s;
    cout<<removeDuplicates(s);
    return 0;
}