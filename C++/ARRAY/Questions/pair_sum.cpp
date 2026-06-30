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
void pair_sum(int *arr,int size,int &ele1,int &ele2){
    cout<<"enter the pair sum: \n";
    int sum;
    cin>>sum;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==sum){
                ele1=arr[i];
                ele2=arr[j];
                return;
            }
        }
    }
    ele1=ele2=-1;
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
    int ele1=0,ele2=0;
    pair_sum(arr,size,ele1,ele2);
    if (ele1 == -1 && ele2 == -1) {
        cout << "No Pair Found\n";
    } else {
        cout << "The pair in array: (" << ele1 << ", " << ele2 << ")\n";
    }

    delete[] arr;
    return 0;
}
