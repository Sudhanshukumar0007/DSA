// You are working as a data analyst at a meteorological department. One day, while reviewing the daily temperature records stored in a system, you notice that the temperatures were supposed to be stored in non-decreasing order, but due to a glitch, a part of the data got shuffled.



// Your task is to identify the shortest continuous block of days (i.e., a subarray of temperature values) such that if you sort only that portion, the entire list of temperatures will be in order.



// You need to write a program to find the length of this shortest subarray.



// Input Format:

// The input contains a list of integers representing daily temperature records, separated by commas.


// Output Format:

// An integer denoting the length of the shortest continuous subarray that needs to be sorted.
// Sample Input:
// 2,6,4,8,10,9,15
// Output:
// 5
#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    vector<int>arr;
    int temp;
    while(ss>>temp){
        arr.push_back(temp);
        if(ss.peek()==',') ss.ignore();
    }
    int n = arr.size();
    int start = 0,end = n-1;
    while(start<n-1 && arr[start]<=arr[start+1]) start++;
    if(start==n-1){
        cout<<0<<endl;
        return 0;
    }
    while(end>0 && arr[end]>=arr[end-1]) end--;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i=start;i<=end;i++){
        mini = min(mini,arr[i]);
        maxi = max(maxi,arr[i]);
    }
    while(start>0 && arr[start-1]>mini) start--;
    while(end<n-1 && arr[end+1]<maxi) end++;
    cout<<end-start+1<<endl;
    return 0;
}