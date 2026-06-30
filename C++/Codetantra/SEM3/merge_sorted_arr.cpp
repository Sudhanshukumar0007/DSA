#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n;
    cout<<"Enter size of the array1\n";
    cin>>n;
    vector<int>arr1(n);
    cout<<"Enter elements of array1 \n";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int m;
    cout<<"Enter size of the array2\n";
    cin>>m;
    vector<int>arr2(m);
    cout<<"Enter elements of array2 \n";
    for(int i= 0;i<m;i++){
        cin>>arr2[i];
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    vector<int>merged;
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            merged.push_back(arr1[i]);
            i++;
        }else{
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        merged.push_back(arr1[i]);
        i++;
    }
    while (j<m)
    {
        merged.push_back(arr2[j]);
        j++;
    }
    cout<<"The Merged sorted array is: \n";
    for(int i=0;i<merged.size();i++){
        cout<<merged[i]<<" ";
    }cout<<endl;
    return 0 ;
}