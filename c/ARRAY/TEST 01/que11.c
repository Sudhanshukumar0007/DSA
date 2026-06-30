#include <stdio.h>
void InsertionSort(int arr[],int n){
     for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
     }
}
int main() {
    int n;
    printf("Enter array size: \n");
    scanf("%d", &n);
    
    int arr[n]; 
    printf("Enter array elements: \n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Given array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Insertion Sort
    InsertionSort(arr,n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
