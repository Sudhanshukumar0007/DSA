#include<iostream>
#include<climits>
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
void max_min(int *arr, int size, int &max, int &min, int &smax, int &smin) {
    if (size < 2) {
        cout << "Array must have at least two elements.\n";
        return;
    }

    max = min = arr[0];
    smax = INT_MIN;
    smin = INT_MAX;

    // First pass to find max and min
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    // Second pass to find second max and min
    for (int i = 0; i < size; i++) {
        if (arr[i] > smax && arr[i] < max) smax = arr[i];
        if (arr[i] < smin && arr[i] > min) smin = arr[i];
    }

    // If smax or smin was never updated
    if (smax == INT_MIN) cout << "No second maximum found (all elements might be equal).\n";
    if (smin == INT_MAX) cout << "No second minimum found (all elements might be equal).\n";
}
int main() {
    int size;
    int max,min,smax,smin;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout<<"Enter the elements of the array:\n";
    initialize_array(arr, size);
    cout<<"Given array: \n";
    print_array(arr, size);
    max_min(arr,size,max,min,smax,smin);
    cout<<"Max and Min of the given array are:"<<max<<" "<<min<<endl;
    cout<<"Second max and second min of the fiven array are: "<<smax<<" "<<smin<<endl;
    delete[] arr;
    return 0;
}
