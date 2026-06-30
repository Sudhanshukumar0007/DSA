#include<stdio.h>
int main(){
    int n;
    int max,min,flag=-1;
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
    //Linear search
    printf("Enter target element: \n");
    int target;
    scanf("%d",&target);
    for (int i=0;i<n;i++){
        if(target==arr[i]){
            flag=i;
            break;
        }
    }
    if(flag!=-1){
        printf("Target element is found at %d\n",flag);
    }
    else{
        printf("Target element not found\n");
    }
    return 0;
}