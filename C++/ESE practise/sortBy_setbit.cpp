#include<iostream>
#include<vector>
using namespace std;
int countSetbits(int n){
    int cnt=0;
	while(n){
        cnt+=n&1;
        n>>=1;
    }
    return cnt;
}
int main(){
	int N;
	cin>>N;
	vector<int>arr(N);
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-1-i;j++){
			int c1=countSetbits(arr[j]);
            int c2=countSetbits(arr[j+1]);
            if(c1<c2){
                swap(arr[j],arr[j+1]);
            }
		}
	}
	cout<<"[";
	for(int i=0;i<N;i++){
		cout<<arr[i];
		if(i<N-1) cout<<", ";
	}
	cout<<"]";
	return 0;
}