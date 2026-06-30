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
void Merge(int *arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *left = new int[n1];
    int *right = new int[n2];

    // Copy data to left[]
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }

    // Copy data to right[]
    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    // Merge the two arrays back into arr[]
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy remaining elements of left[], if any
    while (i < n1) {
        arr[k++] = left[i++];
    }

    // Copy remaining elements of right[], if any
    while (j < n2) {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void splitAndMerge(int *arr,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        splitAndMerge(arr,low,mid);
        splitAndMerge(arr,mid+1,high);
        Merge(arr,low,mid,high);
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
    splitAndMerge(arr,0,size-1);
    print_array(arr,size);
    delete[] arr;
    return 0;
}
