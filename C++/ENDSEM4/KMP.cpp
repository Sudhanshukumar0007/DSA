#include<bits/stdc++.h>
using namespace std;
bool found = false;
vector<int>calcLps(string pattern){
    int m = pattern.length();
    vector<int>lps(m,0);
    int len = 0;
    int i = 1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void KMP(string text,string pattern){
    int n = text.length();
    int m = pattern.length();
    if(m==0) return;
    vector<int>lps = calcLps(pattern);
    int i=0,j=0;
    while(i<n){
         if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            found = true;
            cout<<i-m<<" ";
            j = lps[j-1];
        }
        else if(i<n && text[i]!=pattern[j]){
            if(j>0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
}
int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    KMP(text,pattern);
    if(!found){
        cout<<-1<<endl;
    }
    return 0;
}