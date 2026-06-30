#include<bits/stdc++.h>
using namespace std;
void BucketSort(vector<float>&arr){
    int n = arr.size();
    vector<vector<float>>buckets(n);
    for(int i=0;i<n;i++){
        int bucket_index = arr[i]*n;
        buckets[bucket_index].push_back(arr[i]);
    }
    for(int i=0;i<n;i++){
        sort(buckets[i].begin(),buckets[i].end());
    }
    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<buckets[i].size();j++){
            arr[index++] = buckets[i][j];
        }
    }
}
int main(){
    cout<<"Enter number of elements in the array: ";
    int n;
    cin>>n;
    vector<float>arr(n);
    cout<<"Enter elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BucketSort(arr);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}