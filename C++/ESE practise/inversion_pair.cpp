#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>&arr,int low,int mid,int high){
	int cnt=0;
    vector<int>temp;
    int i=low,j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            cnt+=(mid-i+1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i<=mid)
    {
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
void splitAndMerge(vector<int>&arr,int low,int high,int &InvCnt){
	if(low<high){
		int mid=low+(high-low)/2;
		splitAndMerge(arr,low,mid,InvCnt);
		splitAndMerge(arr,mid+1,high,InvCnt);
		InvCnt+=merge(arr,low,mid,high);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int InvCnt=0;
	splitAndMerge(arr,0,n-1,InvCnt);
	cout<<InvCnt<<endl;
	return 0;
}