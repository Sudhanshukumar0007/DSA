#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    const int mod = 1000000007;
    if(n==1){
        cout<<k%mod<<endl;
        return 0;
    }
    long long same = k%mod;
    long long diff = (k*(k-1))%mod;
    for(int i=3;i<=n;i++){
        long long prevTotal = (same+diff)%mod;
        same = diff;
        diff = (prevTotal*(k-1))%mod;

    }
    cout<<(same+diff)%mod<<endl;
    return 0;
}