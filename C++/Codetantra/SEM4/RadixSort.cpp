#include<bits/stdc++.h>
using namespace std;
void countingSort(vector<int>&arr,int exp){
    int n = arr.size();
    vector<int>count(10,0);
    for(int i=0;i<n;i++){
        int digit = (arr[i]/exp)%10;
        count[digit]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    vector<int>output(n);
    for(int i=n-1;i>=0;i--){
        int digit = (arr[i]/exp)%10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }
    arr = output;
}
void radixSort(vector<int>&arr){
    int max_val = *max_element(arr.begin(),arr.end());
    for(int exp = 1;max_val/exp>0;exp*=10){
        countingSort(arr,exp);
    }
}
int main(){
    cout<<"Enter number of elements in the array: ";
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Original array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    radixSort(arr);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}