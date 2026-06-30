// Hanky gave a challenge to Wanky to perform a magical sort. According to Hanky, dependent sort is a sort where we have to reorder elements of the first array 
//  by the order of elements defined by the second array 
// .



// There are some constraints imposed by Hanky:

// The elements that are not present in the second array but present in the first array should be appended at the end of the sorted values.
// The second array can contain some extra elements that are not part of the first array.
// The remaining elements of array 
//  (those not present in 
// ) must be sorted in ascending order before appending.


// Input Format:

// The first line contains the size of arrays 
//  and 
//  separated by a space.
// The second line of input contains the values of the array 
// , space-separated.
// The third line of input contains the values of the array 
// , space-separated.


// Output Format:

// A single line containing the required sorted values separated by space.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    map<int,int>freq;
    for(int i:arr1) freq[i]++;
    vector<int>result;
    for(int i:arr2){
        if(freq.count(i)){
            while(freq[i]--){
                result.push_back(i);
            }
            freq.erase(i);
        }
    }
    for(auto it:freq){
        while(it.second--){
            result.push_back(it.first);
        }
    }
    for(int i:result){
        cout<<i<<" ";
    }
    return 0;
}