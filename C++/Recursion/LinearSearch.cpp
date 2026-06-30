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
int Linearsearch_recur(int *arr, int size, int idx, int target) {
    if (idx >= size) return -1; // base case: not found
    if (arr[idx] == target) return idx; // found
    return Linearsearch_recur(arr, size, idx + 1, target); // recursive step
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
    int idx=0,target;
    cout<<"Enter the target element:\n";
    cin>>target;
    cout<<"The index of the given element is : \n";
    cout<<Linearsearch_recur(arr,size,idx,target);
    delete[] arr;
    return 0;
}
