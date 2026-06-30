#include<stdio.h>

void ReverseArray(int arr[],int n){
    int i=0,j=n-1;
   while(i<j){
    int temp=arr[i];
     arr[i]=arr[j];
     arr[j]=temp;
     i++;
     j--;
   }
}
int main(){
    int n;
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
    ReverseArray(arr,n);
    printf("Reversed array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}