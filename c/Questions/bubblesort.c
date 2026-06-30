#include<stdio.h>
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
    //Bubble sort 
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array : ");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    //Binary search
    int low=0;
    int high=n-1;
    int idx=-1,target;
    printf("Enter target: ");
    scanf("%d",&target);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(target==arr[mid]){
            idx=mid;
            break;
        }
        else if (target<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if (idx != -1){
    printf("Index of the target in array is: %d",idx);
    }
    else
    printf("Element is not present in the array");
    return 0;
}