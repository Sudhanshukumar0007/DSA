#include<stdio.h>
int LinearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(target==arr[i]){
            return i;
        }
    }
    return -1;
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
    int idx=LinearSearch(arr,n,target);
    if (idx != -1){
    printf("The positon of target is %d ",idx);
    }
    else{
        printf("Element not found");
    }
    return 0;
}