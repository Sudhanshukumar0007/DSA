#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int low,int high,int &cCnt){
   int pivot = arr[high];
   int i = low-1;
   for(int j=low;j<high;j++){
    cCnt++;+*9
    if(arr[j]<pivot){
        i++;
        swap(arr[i],arr[j]);
    }
   }
   swap(arr[i+1],arr[high]);
   return i+1;
}
void quickSort(vector<int>&arr,int low,int high,int &rCnt,int &cCnt){
    if(low<high){
        rCnt++;
        int p = partition(arr,low,high,cCnt);
        quickSort(arr,low,p-1,rCnt,cCnt);
        quickSort(arr,p+1,high,rCnt,cCnt);
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array.\n";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements of the array.\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The given array is \n";
    for(int num:arr){
        cout<<num<<" ";
    }cout<<endl;
    int rCnt=0;
    int cCnt=0;
    quickSort(arr,0,n-1,rCnt,cCnt);
    cout<<"The Sorted  array is \n";
    for(int num:arr){
        cout<<num<<" ";
    }cout<<endl;
    cout<<"Number of recursive calls "<<rCnt<<endl;
    cout<<"Number of comparison "<<cCnt<<endl;
    return 0;
}