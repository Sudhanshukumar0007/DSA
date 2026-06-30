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
// int InversionCount(int *arr,int size){
//     int cnt=0;
//     for(int i=0;i<size;i++){
//         for(int j=i+1;j<size;j++){
//             if(arr[i]>arr[j]) cnt++;
//         }
//     }
//     return cnt;
// }
int mergeAndCount(int *arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *left = new int[n1];
    int *right = new int[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[low + i];
    for (int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low, inv_count = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inv_count += (n1 - i);  // All remaining left[i...] > right[j]
        }
    }

    // Copy leftovers
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    delete[] left;
    delete[] right;

    return inv_count;
}
int splitAndCount(int *arr, int low, int high) {
    int inv_count = 0;

    if (low < high) {
        int mid = low + (high - low) / 2;

        // Count inversions in left half
        inv_count += splitAndCount(arr, low, mid);

        // Count inversions in right half
        inv_count += splitAndCount(arr, mid + 1, high);

        // Count split inversions during merge
        inv_count += mergeAndCount(arr, low, mid, high);
    }

    return inv_count;
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
    cout<<splitAndCount(arr,0,size-1);
    // cout<<InversionCount(arr,size);
    delete[] arr;
    return 0;
}
