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
int  BinarSearch(int arr[],int low,int high,int target){
   
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if (arr[mid]>target)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;

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
    printf("Enter target:\n");
    scanf("%d",&target);
    //Binary search
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
    idx=BinarSearch(arr,0,n-1,target);
    if(idx != -1){
        printf("Target element is found at %d\n",idx);
    }
    else{
        printf("Target element not found\n");
    }
    return 0;
}