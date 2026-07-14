#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>mes(n);
        vector<int>post(m);
        for(int i=0;i<n;i++){
            cin>>mes[i];
        }
        for(int i=0;i<m;i++){
            cin>>post[i];
        }
        int max_prod = INT_MIN;
        for(int i=0;i<m;i++){
            int k =post[i];
            int prod = 0;
            for(int j=0;j<n;j++){
                if(k--){
                    prod+= (-1) * mes[j];
                }else{
                    prod+=mes[j];
                }
            }
            max_prod = max(prod,max_prod);
        }
        cout<<max_prod<<"\n";
    }
    return 0;
}