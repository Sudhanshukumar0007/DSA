#include<bits/stdc++.h>
using namespace std;
bool isFessible(vector<int>pages,int students,int Maxpages){
	int total=0;
	int count=1;
	for(int page:pages){
		if(page>Maxpages) return false;
		if(total+page>Maxpages){
			count++;
			total=page;
		}else{
			total+=page;
		}
	}
	return count<=students;
}
int allocateBooks(vector<int>&pages,int students){
	int books=pages.size();
	if(students>books) return -1;
	int low=*max_element(pages.begin(),pages.end());
	int high=0;
	for(int page:pages) high+=page;
	int result=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		// cout<<mid<<endl;
	if(isFessible(pages,students,mid)){
		result=mid;
		high=mid-1;
	}else{
		low=mid+1;
		}
	}
	return result;
}
int main(){
	int books,students;
	cin>>books>>students;
	vector<int>pages(books);
	for(int i=0;i<books;i++){
		cin>>pages[i];
	}
	cout<<allocateBooks(pages,students)<<endl;
	return 0;
}