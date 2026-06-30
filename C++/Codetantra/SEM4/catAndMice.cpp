#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<char>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int>cats,mice;
    for(int i=0;i<n;i++){
        if(arr[i]=='c')
            cats.push_back(i);
        else if(arr[i]=='m')
            mice.push_back(i);
    }
    int i=0,j=0;
    int count = 0; 
    while(i<cats.size() && j<mice.size()){
        if(abs(cats[i]-mice[j])<=k){
            count++;
            i++;
            j++;
        }else if(cats[i]<mice[j]){
            i++;
        }else{
            j++;;
        }
    }
    cout<<count<<endl;
    return 0;
}