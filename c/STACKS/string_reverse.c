#include<stdio.h>
#include<string.h>
#define STACK_MAX_SIZE 30
char stack[STACK_MAX_SIZE];
int top=-1;

void push(char x){
    if(top==STACK_MAX_SIZE-1){
        printf("Stack is overflow.\n");
    }
    else{
        stack[++top]=x;
    }
}

char pop(){
    if(top==-1){
        printf("Stack is empty.\n");
        return '\0';
    }
    else{
        return stack[top--];
    }
}

void reverse(char str[]){
    int n;
    n=strlen(str);
    for(int i=0;i<n;i++){
        push(str[i]);
    }
    for(int i=0;i<n;i++){
        str[i]=pop();
    }
}

int main(){
    char ch[50],temp;
    printf("Enter a string : ");
    scanf("%s",ch);
    reverse(ch);
    printf("The reversed string is :%s\n",ch);
    return 0;
}