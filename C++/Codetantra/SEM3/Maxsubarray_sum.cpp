#include<bits/stdc++.h>
using namespace std;
int MaxSubarray_Sum(vector<int>&arr,int &start,int &end){
    int max_sum=0;
    int i=0;
    int curr_sum=0;
    int temp_start=0;
    while(i<arr.size()){
        curr_sum+=arr[i];
        if(curr_sum>max_sum){
            max_sum=curr_sum;
            start=temp_start;
            end=i;
        }
        if(curr_sum<0){
            max_sum=0;
            curr_sum=0;
            temp_start=i+1;
        }
        i++;
    }
    return max_sum;
}
int main(){
    int n;
    cout<<"Enter the size of array.\n";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The given array is\n";
    for(int a:arr){
        cout<<a<<" ";
    }cout<<endl;
    cout<<"The max subarray sum of the given array is \n";
    int start=0;
    int end=0;
    cout<<MaxSubarray_Sum(arr,start,end)<<endl;
    cout<<"The subarray having the max sum is\n";
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}