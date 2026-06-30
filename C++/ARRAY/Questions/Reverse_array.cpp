#include<iostream>
#include<algorithm>
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
void reverse(int *arr,int size){
    int i=0;
    int j=size-1;
    while(i<=j){
        swap(arr[i++],arr[j--]);
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
    cout<<"Reversed array: \n";
    reverse(arr,size);
    print_array(arr,size);
    delete[] arr;
    return 0;
}
