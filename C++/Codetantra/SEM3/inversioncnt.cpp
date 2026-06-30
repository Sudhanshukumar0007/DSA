#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>&arr,int low,int mid,int high){
    int cnt=0;
    int i=low;
    int j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            cnt+=(mid-1+i);
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
void splitAndMerge(vector<int>&arr,int low,int high,int &InversionCnt){
    if(low<high){
        int mid = low + (high-low)/2;
        splitAndMerge(arr,low,mid,InversionCnt);
        splitAndMerge(arr,mid+1,high,InversionCnt);
        InversionCnt += merge(arr,low,mid,high);
    }
}
int main(){
    int n;
    cout<<"Enter size of the array "<<endl;
    cin>>n;
    vector<int>vec(n);
    cout<<"Enter elements of the array\n";
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int InversionCnt=0;
    splitAndMerge(vec,0,n-1,InversionCnt);
    cout<<"The inversion count is "<<InversionCnt<<endl;
    return 0;
}