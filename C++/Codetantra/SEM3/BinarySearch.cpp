#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>&arr,int low,int high,int target){
    if(low>high) return -1;
    int mid = low + (high-low)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target) return BinarySearch(arr,low,mid-1,target);
    else return BinarySearch(arr,mid+1,high,target);
}
int main(){
    int n;
    cout<<"Enter size of the array.\n";
    cin>>n;
    vector<int>vec(n);
    cout<<"Enter elements of the array in sorted manner"<<endl;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int target;
    cout<<"Enter the target"<<endl;
    cin>>target;
    int idx=BinarySearch(vec,0,n-1,target);
    cout<<"Index of the target element in the array is "<<idx<<endl;
    return 0;
}