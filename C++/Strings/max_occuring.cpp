#include<iostream>
#include<string>
using namespace std;
void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
char getMaxOccuringChar(string str) {
    int freq[26] = {0};
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch>='a' && ch<='z'){
            freq[ch -'a']++;
        }
    }
    int maxi=0;
    for(int i=0;i<26;i++){
        if(freq[i]>freq[maxi]){
            maxi=i;
        }
    }
    return 'a'+maxi;
}
int main(){
    string str;
    cout<<"Enter the string\n";
    cin>>str;
    cout<<"The Maximum occouring element of the string is : \n";
    cout<<getMaxOccuringChar(str);
    return 0;
}