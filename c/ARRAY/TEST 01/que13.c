#include<stdio.h>
void rotatedarray(int arr[],int n,int k){
    k=k%n;
    int temp[n];
    for (int i=0;i<k;i++){
        temp[i]=arr[n-k+i];
    }
    for(int i=k;i<n;i++){
        temp[i]=arr[i-k];
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int n=10;
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    printf("Given  array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    int d;
    printf("Enter the no of rotations.\n");
    scanf("%d",&d);
    rotatedarray(arr,n,d);
    printf("Rotated array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    return 0;
}