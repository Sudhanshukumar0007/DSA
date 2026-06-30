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
void Delete(int *arr, int &size,int pos) {
    // Shift elements left from pos+1 to end
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;  // Reduce size after deletion
}
void remove_duplicates(int *arr, int &size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; ) {
            if(arr[i] == arr[j]) {
                Delete(arr, size, j);
                // Don't increment j; check the new element at j
            } else {
                j++;  // Only increment if no deletion
            }
        }
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
    remove_duplicates(arr,size);
    cout<<"Array after removing duplicates : ";
    print_array(arr,size);
    delete[] arr;
    return 0;
}
