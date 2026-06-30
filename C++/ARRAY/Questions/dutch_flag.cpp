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
// void Sort_0s_1s_2s(int *arr,int size){
//     int count_zero=0;
//     int count_one=0;
//     int count_two=0;
//     for(int i=0;i<size;i++){
//         if(arr[i]==0) count_zero++;
//         else if(arr[i]==1) count_one++;
//         else count_two++;
//     }
//     for(int i=0;i<count_zero;i++){
//         arr[i]=0;
//     }
//     for(int i=count_zero;i<count_zero+count_one;i++){
//         arr[i]=1;
//     }
//     for(int i=count_zero+count_one;i<size;i++){
//         arr[i]=2;
//     }
// }
 void Sort_0s_1s_2s(int *arr,int size){
    int low=0,mid=0,high=size-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
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
    cout<<"Sorted array in 0s 1s and 2s in order : \n";
    Sort_0s_1s_2s(arr,size);
    print_array(arr,size);
    delete[] arr;
    return 0;
}
