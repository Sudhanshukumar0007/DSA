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
int getSum(int *arr, int size) {
    if (size == 0) return 0;
    return arr[size - 1] + getSum(arr, size - 1);
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
    int sum=getSum(arr,size);
    cout<<"Sum of the elements of the given array is\n";
    cout<<sum;

    delete[] arr;
    return 0;
}
