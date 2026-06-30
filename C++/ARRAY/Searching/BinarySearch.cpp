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
void BubbleSort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                // print_array(arr,size); To see how bubble sort works
            }
        }
    }
    cout<<"Sorted array\n";
    print_array(arr,size);
}
// Basic implementation
// int BinarySearch(int *arr,int low,int high,int target){
//     while(low<=high){
//         int mid=low+(high-low)/2;
//         if(arr[mid]==target){
//             return mid;
//         }
//         else if (arr[mid]>target)
//         {
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     return -1;
// }



// Recursive binary search
int BinarySearch(int *arr,int low,int high,int target){
    if(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) return BinarySearch(arr,low,mid-1,target);
        else return BinarySearch(arr,mid+1,high,target);
        
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
    BubbleSort(arr,size);
    int target;
    cout<<"Enter the target element\n";
    cin>>target;
    int index=BinarySearch(arr,0,size-1,target);
    if(index!=-1){
        cout<<"element found at index : "<<index<<endl;
    }
    else{
        cout<<"element not found";
    }
    delete[] arr;
    return 0;
}
