#include<stdio.h>
#include<stdbool.h>

void BubbleSort(int arr[],int n){
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }

}

}

int main(){
    int n,target;
    int idx;
    bool sorted_array=true;
    printf("Enter array size: \n");
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
    printf("\n");
    //To check if array is sorted
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
             sorted_array=false;
            break;
        }
    }
    if(!sorted_array) {
        BubbleSort(arr,n);
         printf("Sorted array: \n");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");}
        else{
            printf("Array is already sorted");
        }
    return 0;
}