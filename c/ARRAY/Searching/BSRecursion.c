#include<stdio.h>
int BinarySearch(int arr[],int low,int high,int target){
    if(low>high){
        return-1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==target) {
        return mid;}
    else if (arr[mid]>target) {
        return BinarySearch(arr,low,mid-1,target);}
    else 
        return BinarySearch(arr,mid+1,high,target);
}

int main(){
    int n,tar;
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter target element: \n");
    scanf("%d",&tar);
    int targetidx=BinarySearch(arr,0,n-1,tar);
    if(targetidx != -1){
        printf("Index of the target element is %d\n",targetidx);
    }
    else{
        printf("Target element not found\n");
    }
    return 0;
}