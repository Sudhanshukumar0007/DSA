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

void interleave(int *arr1, int *arr2, int *arr3, int size1, int size2) {
    int i = 0, j = 0, k = 0;
    while(i < size1 && j < size2) {
        arr3[k++] = arr1[i++];
        arr3[k++] = arr2[j++];
    }
    while(i < size1) {
        arr3[k++] = arr1[i++];
    }
    while(j < size2) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;
    cout << "Enter sizes of the two arrays: ";
    cin >> size1 >> size2;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];
    int *arr3 = new int[size1 + size2];

    cout << "Enter the elements of array1:\n";
    initialize_array(arr1, size1);
    cout << "Given array1:\n";
    print_array(arr1, size1);

    cout << "Enter the elements of array2:\n";
    initialize_array(arr2, size2);
    cout << "Given array2:\n";
    print_array(arr2, size2);

    cout << "Interleaved array:\n";
    interleave(arr1, arr2, arr3, size1, size2);
    print_array(arr3, size1 + size2);

    // Free memory
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
