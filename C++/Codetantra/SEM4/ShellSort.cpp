#include<bits/stdc++.h>
using namespace std;
void shellSort(vector<int>&arr){
    int n = arr.size();
    for(int gap = n/2;gap>=1;gap/=2){
        for(int i=gap;i<n;i++){
            int temp= arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>temp){
                arr[j] = arr[j-gap];
                j-=gap;
            }
            arr[j] = temp;
        }
    }
}
int main(){
    cout<<"Enter number of elements in the array: ";
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    shellSort(arr);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}