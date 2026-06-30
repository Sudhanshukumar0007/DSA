#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int start=low;
    int end=high;
    while(start<end){
        while(start<end && arr[start] <= pivot) start++;
        while(arr[end]>pivot) end--;
        if(start<end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[end],arr[low]);
    return end;
}
void quickSort(vector<int>&arr,int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter element of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The given Array is "<<endl;
    for(int num:arr){
        cout<<num<<" ";
    }cout<<endl;
    quickSort(arr,0,n-1);
    cout<<"The sorted array is "<<endl;
    for(int num:arr){
        cout<<num<<" ";
    }cout<<endl;
    return 0;
}