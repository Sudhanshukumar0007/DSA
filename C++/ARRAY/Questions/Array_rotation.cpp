#include<iostream>
#include<algorithm>
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

void reverse(int arr[], int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void Left_rotate_array(int *arr, int size) {
    int k;
    cout << "Enter number of rotations: ";
    cin >> k;
    k = k % size; // handle rotations greater than size

    // Left rotation by k using reversal algorithm
    reverse(arr, 0, k - 1);
    reverse(arr, k, size - 1);
    reverse(arr, 0, size - 1);
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

    Left_rotate_array(arr, size);

    cout << "Left Rotated array: \n";
    print_array(arr, size);

    delete[] arr;
    return 0;
}
