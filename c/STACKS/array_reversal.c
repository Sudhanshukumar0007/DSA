#include<stdio.h>
#define STACK_MAX_SIZE 30
int stack[STACK_MAX_SIZE];
int top=-1;

void push(int x){
    if(top==STACK_MAX_SIZE-1){
        printf("Stack is overflow.\n");
    }
    else{
        stack[++top]=x;
    }
}

int pop(){
    if(top==-1){
        printf("Stack is underflow.\n");
        return -1;
    }
    else return stack[top--];
}

int main(){
    int size,index;
    int arr[30];
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    if(size<0){
        printf("Invalid input ! Size should be grater than zero.\n");
        return 0;
    }
    for(index = 0; index < size; index++) {
		printf("Enter arr[%d] : ",index);
		scanf("%d",&arr[index]);
	}
	printf("Array before reversing : ");
	for(index = 0; index < size; index++) {
		printf("%d ",arr[index]);
	}
	printf("\n");
    
        for(int i=0;i<size;i++){
           push(arr[i]);
        }
        for (int i=0;i<size;i++){
            arr[i]=pop();
        }
        printf("Array after reversing : ");
        for(index = 0; index < size; index++) {
            printf("%d ",arr[index]);
        }
        printf("\n");
    return 0;

}