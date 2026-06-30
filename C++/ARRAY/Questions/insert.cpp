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
void Delete(int *arr, int &size) {
    cout << "Enter position to delete:\n";
    int pos;
    cin >> pos;

    if (pos < 0 || pos >= size) {
        cout << "Invalid position.\n";
        return;
    }

    // Shift elements left from pos+1 to end
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;  // Reduce size after deletion
}

void insert(int *arr, int &size, int pos, int x) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position.\n";
        return;
    }

    // Shift elements to the right from end to pos
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = x;
    size++; // Increase size after insertion
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
    cout<<"Enter the position  and element: \n";
    int pos,ele;
    cin>>pos>>ele;
    insert(arr,size,pos,ele);
    print_array(arr,size);
    Delete(arr,size);
    print_array(arr,size);
    delete[] arr;
    return 0;
}
