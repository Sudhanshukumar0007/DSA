#include<iostream>
using namespace std;

void initialize_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shift_zeroes_in_place(int *arr, int size) {
    int index = 0;  // Position to place the next non-zero element

    // Move all non-zero elements to the front
    for(int i = 0; i < size; i++) {
        if(arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    // Fill the remaining positions with zeroes
    while(index < size) {
        arr[index++] = 0;
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter the elements of the array:\n";
    initialize_array(arr, size);

    cout << "Given array: \n";
    print_array(arr, size);

    shift_zeroes_in_place(arr, size);

    cout << "Zeroes shifted array:\n";
    print_array(arr, size);

    delete[] arr;
    return 0;
}
