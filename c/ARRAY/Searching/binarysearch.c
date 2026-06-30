#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[5]={1,2,3,4,5};
    int low=0,high=4,target;
    bool flag=false;
    int idx=-1;
    printf("Enter target element: ");
    scanf("%d",&target);
   while(low<=high){
    int mid=(low+high)/2;
    if(target==arr[mid]){
        idx=mid;
        flag=true;
        break;
    }
    else if(target>arr[mid]){
        low=mid+1;
    }
    else if(target<arr[mid]){
        high=mid-1;
    }
   }
   if(flag){
    printf("The index of the target element is %d ",idx);
}
else{
    printf("Element not found");
}
    return 0;
}