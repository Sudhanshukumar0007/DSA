#include<bits/stdc++.h>
using namespace std;
int  merge(vector<int>&arr,int low,int mid,int high){
   int cnt = 0;
   vector<int>temp;
   int i=low,j=mid+1;
   while(i<=mid && j<=high){
    cnt++;
    if(arr[i]<=arr[j]){
        temp.push_back(arr[i]);
        i++;
    }else{
        temp.push_back(arr[j]);
        j++;
    }
   }
   while(i<=mid){
    temp.push_back(arr[i]);
    i++;
   }
   while(j<=high){
    temp.push_back(arr[j]);
    j++;
   }
   for(int k=0;k<temp.size();k++){
     arr[k+low]=temp[k];
   }
   return cnt;
}
void  splitAndmerge(vector<int>&arr,int low,int high,int &recCnt,int &compCnt){
    recCnt++;
   if(low<high){
    int mid = low + (high-low)/2;
    splitAndmerge(arr,low,mid,recCnt,compCnt);
    splitAndmerge(arr,mid+1,high,recCnt,compCnt);
    compCnt += merge(arr,low,mid,high);
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
    int recCnt=0;
    int compCnt=0;
    splitAndmerge(arr,0,n-1,recCnt,compCnt);
    cout<<"The sorted array is "<<endl;
    for(int num:arr){
        cout<<num<<" ";
    }cout<<endl;
    cout<<"The number of recursive calls "<<recCnt<<endl;
    cout<<"The number of comparison counts "<<compCnt<<endl;
    return 0;
}