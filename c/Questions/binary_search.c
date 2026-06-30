#include<stdio.h>
int BinarySearch(int arr[],int low,int high,int target){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(target==arr[mid]){
        return mid;
    }
    else if (target<arr[mid]){
        return BinarySearch(arr,low,mid-1,target);
    }
    else{
        return BinarySearch(arr,mid+1,high,target);
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
    int target;
    printf("Enter target: ");
    scanf("%d",&target);
    int idx=BinarySearch(arr,0,n-1,target);
    printf("The positon of target is %d: ",idx);
    return 0;
}