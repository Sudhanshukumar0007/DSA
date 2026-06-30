#include<stdio.h>
//Insertion sort

void SelectionSort(int arr[],int n){
   for (int i = 0; i < n - 1; i++) {
        int min_idx = i;  // Assume i is the smallest
        for (int j = i + 1; j < n; j++) {  // Find the minimum element
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap if min_idx changed
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
int main(){
    int n;
    int arr[20];
    printf("Enter Size of array: \n");
    scanf("%d",&n);
    printf("Enter elements of array:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Given array is :");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Sorted array: ");
    SelectionSort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}