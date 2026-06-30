#include<stdio.h>
#define MAX_SIZE 10
int top=-1;
int stack[MAX_SIZE];
void push(int x){
    if(top==MAX_SIZE-1){
        printf("Stack overflow.\n");
        return;
    }
    stack[++top]=x;
}
int pop(){
    if(top==-1){
        printf("Stack underflow.\n");
        return -1;
    }
    return stack[top--];
}
int main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Given array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        push(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i]=pop();
    }
    printf("Array after reversing: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}