#include<iostream>
using namespace std;

void initialize_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int  BinarySearch(int *arr,int low,int high,int target){
    if(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
           return BinarySearch(arr,low,mid-1,target);
        }
        else{
            return BinarySearch(arr,mid+1,high,target);
        }
    }
    return -1;
}
int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout<<"Enter the elements of the array:\n";
    initialize_array(arr, size);
    cout<<"Given array: \n";
    print_array(arr, size);
    cout<<"Enter the target element: ";
    int target;
    cin>>target;
    int idx=BinarySearch(arr,0,size-1,target);
    cout<<"Index of the target element in the array is : \n";
    cout<<idx;
    delete[] arr;
    return 0;
}
