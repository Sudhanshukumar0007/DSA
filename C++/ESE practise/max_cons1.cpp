#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	int maxlen=0;
	for(int i=0;i<n;i++){
		int cnt=0;
		int zCnt=0;
		for(int right=i;right<n;right++){
			if(arr[right]==0) zCnt++;
			if(zCnt>k) break;
			cnt++;
		}
		maxlen=max(maxlen,cnt);
	}
	cout<<maxlen;
	return 0;
}