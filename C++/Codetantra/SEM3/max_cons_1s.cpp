#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n;
    cout<<"Enter size of the array.\n";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Given array is \n";
    for(int a:arr){
        cout<<a<<" ";
    }cout<<endl;
    int k;
    cout<<"Enter the number of flips \n";
    cin>>k;
    int max_length=0;
    for(int i=0;i<n;i++){
        int z_cnt=0;
        int cnt=0;
        for(int right=i;right<n;right++){
            if(arr[right]==0) z_cnt++;
            if(z_cnt>k) break;
            cnt++;
        }
        max_length=max(max_length,cnt);
    }
    cout<<"The max length of consecutive ones after "<<k<<" flips "<<max_length<<endl;
    return 0 ;
}