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
bool is_sorted(int *arr,int size){
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]) return false;
    }
    return true;
}
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void QuickSort(int *arr,int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
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
    if(is_sorted(arr,size)){
        cout<<"Array is sorted.\n";
    }else{
        cout<<"Array is not sorted.\n";
        QuickSort(arr,0,size-1);
        cout<<"sorted array: \n";
        print_array(arr,size);
    }
    delete[] arr;
    return 0;
}
