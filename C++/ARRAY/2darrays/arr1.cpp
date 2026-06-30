#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter rows and columns of the array\n";
    cin>>m>>n;
    int arr1[m][n];
    cout<<"Enter elements of array\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"Given array\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr1[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    return 0;
}