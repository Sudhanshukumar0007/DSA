#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long curr_sum = 0;
        bool possible = true;
        for(int i=1;i<=n;i++){
            curr_sum += a[i-1];
            long long req_sum = (i*(i+1))/2;
            if(curr_sum<req_sum){
                possible = false;
                break;
            }
        }
        if(possible){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}