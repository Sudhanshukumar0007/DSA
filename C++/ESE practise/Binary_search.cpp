#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>&arr,int low,int high,int target){
  while(low<=high){
    int mid = low+(high-low)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target) 
        high = mid-1;
    else
        low = mid + 1 ;
  }
  return -1;
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
    sort(vec.begin(),vec.end());
    int idx=BinarySearch(vec,0,n-1,target);
    cout<<"Index of the target element in the array is "<<idx<<endl;
    return 0;
}