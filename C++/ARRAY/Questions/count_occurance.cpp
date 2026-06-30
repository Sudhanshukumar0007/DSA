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
int count_occurance(int *arr,int size,int x){
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==x) count++;
    }
    return count;
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
    cout<<"Enter number you want to count\n";
    int x;
    cin>>x;
    cout<<"Occurance : "<<count_occurance(arr,size,x)<<endl;
    delete[] arr;
    return 0;
}
