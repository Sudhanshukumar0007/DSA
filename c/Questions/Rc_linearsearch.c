#include<stdio.h>
int LinearSearch(int arr[],int index,int n,int target){
    if(index==n) return -1;
    if(arr[index]==target) return index;
    return LinearSearch(arr,index+1,n,target);
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
    //Linear search
    int target;
    printf("Enter target: ");
    scanf("%d",&target);
    int idx=LinearSearch(arr,0,n,target);
    if (idx != -1){
    printf("The positon of target is %d ",idx);
    }
    else{
        printf("Element not found");
    }
    return 0;
}