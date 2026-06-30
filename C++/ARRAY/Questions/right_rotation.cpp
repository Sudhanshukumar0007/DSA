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

void rotate_array_right(int *arr, int size) {
    int k;
    cout << "Enter number of right rotations: ";
    cin >> k;
    k = k % size; // handle rotations greater than size

    // Right rotation using reversal
    reverse(arr, size - k, size - 1); // Step 1
    reverse(arr, 0, size - k - 1);    // Step 2
    reverse(arr, 0, size - 1);        // Step 3
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

    rotate_array_right(arr, size);

    cout << "Right rotated array: \n";
    print_array(arr, size);

    delete[] arr;
    return 0;
}
