#include<stdio.h>



int LinearSearch(int arr[],int index,int target,int n){
if(index>=n){
    return -1;
}
if(arr[index]==target){
    return index;
}
return LinearSearch(arr,index+1,target,n);
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
    int targetidx=LinearSearch(arr,0,tar,n);
    if(targetidx != -1){
        printf("Index of the target element is %d\n",targetidx);
    }
    else{
        printf("Target element not found\n");
    }
    return 0;
}