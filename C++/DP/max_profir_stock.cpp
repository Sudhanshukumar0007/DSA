#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int buy1 = INT_MIN;
    int buy2 = INT_MIN;
    int sell1=0,sell2=0;
    for(int a:arr){
        buy1 = max(buy1,-a);
        sell1 = max(sell1,buy1+a);

        buy2=max(buy2,sell1-a);
        sell2=max(sell2,buy2+a);
    }
    cout<<sell2<<endl;
    return 0;
}