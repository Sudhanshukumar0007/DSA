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

void prefix_sum(int *arr, int *prefix, int size) {
    prefix[0] = arr[0];
    for(int i = 1; i < size; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
}
int Range_sum(int *prefix,int L,int R){
    if(L==0) return prefix[R];
    if(L>0)  return prefix[R]-prefix[L-1];
}
int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    int *prefix=new int[size];
    cout<<"Enter the elements of the array:\n";
    initialize_array(arr, size);
    cout<<"Given array: \n";
    print_array(arr, size);
    cout<<"Prefix array: \n";
    prefix_sum(arr,prefix,size);
    print_array(prefix,size);
    cout<<"Sum in the range 1 to 3 is :"<<Range_sum(prefix,1,3)<<endl;
    delete[] arr;
    return 0;
}
