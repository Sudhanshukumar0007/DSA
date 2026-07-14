#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt = 0;
        int max_count = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                cnt++;
                max_count = max(cnt,max_count);
            }
            else{
                cnt=0;
            }
        }
        if(max_count==0){
            cout<<0<<"\n";
        }
        else{
            cout<<(max_count+1)/2<<"\n";
        }
    }
    return 0;
}