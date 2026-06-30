#include<iostream>
using namespace std;

void initialize_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to count frequency
void frequency_count(int *arr, int *freq, int size) {
   for(int i=0;i<size;i++){
    freq[i]=-1;
   }
   for(int i=0;i<size;i++){
    if(freq[i]==-1){
        int count=1;
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                count++;
                freq[j]=0;
            }
        }
        freq[i]=count;
    }
   }
    cout << "\nElement\tFrequency\n";
    for(int i = 0; i < size; i++) {
        if(freq[i] != 0) {
            cout << arr[i] << "\t" << freq[i] << endl;
        }
    }

}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    int *freq = new int[size];

    cout << "Enter the elements of the array:\n";
    initialize_array(arr, size);

    cout << "Given array: \n";
    print_array(arr, size);

    frequency_count(arr, freq, size);

    delete[] arr;
    delete[] freq;

    return 0;
}
