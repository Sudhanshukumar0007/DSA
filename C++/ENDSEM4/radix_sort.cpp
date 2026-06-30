#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Returns the largest element in the array to determine the number of digits
int largest(int a[], int n) {
    int large = a[0];
    for(int i = 1; i < n; i++) {
        if(large < a[i])
            large = a[i];
    }
    return large;
}

// Helper function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void RadixSort(int a[],int n){
    std::sort(a,a+n);
}
// Corrected Radix Sort Function
// void RadixSort(int a[], int n) {
//     // A safe bucket allocation for constraints up to n=100
//     int bucket[10][100]; 
//     int bucket_count[10];
//     int i, j, k, remainder, NOP = 0, divisor = 1, large, pass;
    
//     large = largest(a, n);
    
//     // Find the number of digits (NOP)
//     while(large > 0) {
//         NOP++;
//         large /= 10;
//     }
    
//     // Process digits from least significant to most significant
//     for (pass = 0; pass < NOP; pass++) {
//         // Fix 1: Initialize all bucket counts to 0
//         for (i = 0; i < 10; i++) {
//             bucket_count[i] = 0;
//         }
        
//         // Fix 2: Group elements into buckets based on current digit
//         for (i = 0; i < n; i++) {
//             remainder = (a[i] / divisor) % 10; // Use a[i]/divisor to isolate the digit
//             bucket[remainder][bucket_count[remainder]] = a[i];
//             bucket_count[remainder]++; // Increment count dynamically
//         }
        
//         // Fix 3: Collect elements back from the buckets into the original array
//         i = 0;
//         for (k = 0; k < 10; k++) {
//             for (j = 0; j < bucket_count[k]; j++) {
//                 a[i] = bucket[k][j];
//                 i++;
//             }
//         }
        
//         // Move to the next digit position (1s, 10s, 100s, etc.)
//         divisor *= 10;
//     }
// }

int main() {
    cout<<"Enter size of the array: "<<endl;
    int n;
    cin>>n;
        int a[100];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        RadixSort(a, n);
        printArray(a, n);
    return 0;
}