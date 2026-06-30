#include<bits/stdc++.h>
using namespace std;
vector<int> countingSort(vector<int>&arr){
    int n = arr.size();
    int max_val = *max_element(arr.begin(),arr.end());

    vector<int>count(max_val+1,0);
    for(int i=0;i<n;i++){
        int x = arr[i];
        count[x]++;
    }
    for(int i=1;i<=max_val;i++){
        count[i] += count[i-1];
    }
    vector<int>output(n);
    for(int i=n-1;i>=0;i--){
        int x =arr[i];
        output[count[x]-1]=x;
        count[x]--;
    }
    return output;
}
int main(){
    cout<<"Enter number of elements in the array: "<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }cout<<endl;
    vector<int> sorted_arr = countingSort(arr);
    cout<<"After sorting inside function: ";
    for(int x : sorted_arr) cout<<x<<" ";
    cout<<endl;
    return 0;
}