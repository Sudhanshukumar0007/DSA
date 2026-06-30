#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
	getline(cin, line);
	stringstream ss(line);
	vector<int>nums;
	string temp;
	while(getline(ss,temp, ',')){
		nums.push_back(stoi(temp));
	}
	int n=nums.size();
	int expected_sum=n*(n+1)/2;
	int actual_sum=0;
	for(int num:nums){
		actual_sum+=num;
	}
	int ans=expected_sum-actual_sum;
	cout<<abs(ans)<<endl;
	return 0;
}