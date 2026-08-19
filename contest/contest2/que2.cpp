#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        vector<int>b(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int j=0;j<m;j++){
            cin>>b[j];
        }
        long long ha = a[0] + (n-1);
        long long hb = b[0] + (m-1);
        if(ha>=hb){
            cout<<1<<endl;
        }else{
            cout<<2<<endl;
        }
    }
    return 0;
}