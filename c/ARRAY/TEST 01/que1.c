#include<stdio.h>
int main(){
    int n;
    int max,min;
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
    max=arr[0];
    min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("MAx : %d ,MIN : %d\n",max,min);
    return 0;
}