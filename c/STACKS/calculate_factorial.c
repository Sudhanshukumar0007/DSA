#include<stdio.h>
#define STACK_MAX_SIZE 20
int stack[STACK_MAX_SIZE];
int top=-1;

void push(int x){
    if(top==STACK_MAX_SIZE-1){
        printf("Stack is overflow.\n");
        return ;
    }
    else{
        stack[++top]=x;
    }
}

int pop(){
    if(top==-1){
        printf("Stack is empty.\n");
        return -1;
    }
    else{
        return stack[top--];
    }
}

int factorial(int n){
    int i=1;
    push(1);
    for (int i=1;i<=n;i++){
        push(pop()*i);
    }
    return pop();
}


void main(){
    int n;
    printf("Enter an integer : ");
    scanf("%d",&n);
    if(n<0){
        printf("Invalid integer! Integer should be greater than or equal to 0.");
        return;
    }
    printf("Factorial of %d is : %d",n,factorial(n));
}