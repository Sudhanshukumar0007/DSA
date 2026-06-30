#include<stdio.h>
int main(){
    int n;
    printf("Enter size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Given array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\n");
    printf("Sorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}




// // By chatgpt
// #include <stdio.h>

// // Optimized Bubble Sort
// void OptimizedBubbleSort(int arr[], int n) {
//     int swapped;
//     int lastUnsorted = n - 1; // Track the last unsorted index

//     for (int i = 0; i < n - 1; i++) {
//         swapped = 0;
//         int newLastUnsorted = 0; // Track the last swap position

//         for (int j = 0; j < lastUnsorted; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 // Swap elements
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//                 swapped = 1;
//                 newLastUnsorted = j; // Update the last swap position
//             }
//         }

//         lastUnsorted = newLastUnsorted; // Reduce the range of comparisons

//         if (swapped == 0) break; // Exit if no swaps happened
//     }
// }

// int main() {
//     int n;
//     printf("Enter size of the array: ");
//     scanf("%d", &n);

//     int arr[n];
//     printf("Enter array elements:\n");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     printf("Given array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     OptimizedBubbleSort(arr, n);

//     printf("\nSorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }
