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
void merge(int *arr, int low, int mid, int high, int &comparison_count, int &merge_count) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        comparison_count++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    merge_count++;

    delete[] L;
    delete[] R;
}

void splitandmerge(int *arr, int low, int high, int &comparison_count, int &merge_count) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        splitandmerge(arr, low, mid, comparison_count, merge_count);
        splitandmerge(arr, mid + 1, high, comparison_count, merge_count);
        merge(arr, low, mid, high, comparison_count, merge_count);
    }
}

int main() {
    int comparison_count=0;
    int merge_count=0;
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout<<"Enter the elements of the array:\n";
    initialize_array(arr, size);
    cout<<"Given array: \n";
    print_array(arr, size);
    splitandmerge(arr,0,size-1,comparison_count,merge_count);
    cout<<"Sorted array: \n";
    print_array(arr,size);
    cout << "Total comparisons: " << comparison_count << endl;
    cout << "Total merges: " << merge_count << endl;

    delete[] arr;
    return 0;
}
