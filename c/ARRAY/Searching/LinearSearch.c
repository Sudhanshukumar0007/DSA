#include<stdio.h>
#include<stdbool.h>
int main(){
    int n,tar,idx=-1;
    bool flag=false;
    printf("Enter array size: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The given array is :\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter the target element you want to search: \n");
    scanf("%d",&tar);
    for(int i=0;i<n;i++){
        if(arr[i]==tar)
        {
            printf("%d index of target\n",i);
           flag=true;
        }
    }
    if (!flag){
        printf("target element not found\n");
    }
    return 0;
}