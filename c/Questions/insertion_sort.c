#include<stdio.h>
//Insertion sort

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;  
        }
        arr[j+1]=temp;
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
    insertionSort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}