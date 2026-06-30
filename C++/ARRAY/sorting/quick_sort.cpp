#include<iostream>
#include<algorithm>
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
int Partition(int *arr,int low,int high){
    int pivot=arr[low];
    int down=low+1,up=high,temp;
    while(down<=up){
        while(arr[down]<=pivot && down<=up){
            down++;
        }
        while(arr[up]>pivot){
            up--;
        }
        if(down<up){
            swap(arr[down],arr[up]);
        }
    }
    swap(arr[low],arr[up]);
return up;
}
void QuickSort(int *arr,int low,int high){
    if(low<high){
    int p=Partition(arr,low,high);
    QuickSort(arr,low,p-1);
    QuickSort(arr,p+1,high);
    }
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
    QuickSort(arr,0,size-1);
    cout<<"Sorted array: \n";
    print_array(arr,size);
    delete[] arr;
    return 0;
}
