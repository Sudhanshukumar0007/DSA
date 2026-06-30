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
bool is_Sorted(int *arr, int low, int high) {
    if (low >= high) return true;  // Base case: 0 or 1 element

    if (arr[low] > arr[low + 1]) return false;

    return is_Sorted(arr, low + 1, high);  // Recurse on next index
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
    if(is_Sorted(arr,0,size-1)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    delete[] arr;
    return 0;
}
