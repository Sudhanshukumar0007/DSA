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
int max_sum(int *arr, int size, int &start, int &end) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    int temp_start = 0;
    
    for (int i = 0; i < size; i++) {
        current_sum += arr[i];

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }

        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }

    return max_sum;
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
    int start = 0, end = 0;
    int max = max_sum(arr, size, start, end);

    cout << "Max sum: " << max << endl;
    cout << "Subarray from index " << start << " to " << end << ": ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
