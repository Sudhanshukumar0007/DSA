#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter size of the array and the value of k\n";
    cin>>n>>k;
    vector<int>arr(n);
    cout<<"Enter the elements of the array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The given array is \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
   sort(arr.begin(), arr.end(), greater<int>());  // descending for ints
    cout<<"Kth largest element of the array is \n";
    cout<<arr[k-1]<<endl;
}