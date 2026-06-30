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
int MedianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] < arr[low])
        swap(arr[mid], arr[low]);
    if (arr[high] < arr[low])
        swap(arr[high], arr[low]);
    if (arr[high] < arr[mid])
        swap(arr[high], arr[mid]);

    // Median is now at mid
    swap(arr[low], arr[mid]);
    return arr[low]; // Use as pivot
}

int MedianPartition(int arr[], int low, int high) {
    int pivot = MedianOfThree(arr, low, high);
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void MedianQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = MedianPartition(arr, low, high);
        MedianQuickSort(arr, low, p - 1);
        MedianQuickSort(arr, p + 1, high);
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
    MedianQuickSort(arr,0,size-1);
    cout<<"Sorted array: \n";
    print_array(arr,size);
    delete[] arr;
    return 0;
}
