#include<iostream>
using namespace std;
int MaxSubarraySum(int *arr,int size){
	int max = 0;
    int curr = 0;
    for(int i=0;i<size;i++){
        curr+=arr[i];
        if(curr>max){
            max=curr;
        }
        if(curr<0){
            curr=0;
        }
    }
    return max;
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=MaxSubarraySum(arr,n);
	cout<<ans<<endl;
	return 0;
}