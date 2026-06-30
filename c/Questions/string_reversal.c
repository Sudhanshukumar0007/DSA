#include<stdio.h>
#include<string.h>
# define MAX_SIZE 50
int top=-1;
char stack[MAX_SIZE];
void push(char x){
    if(top==MAX_SIZE-1){
        printf("Stack overflow.\n");
        return;
    }
    stack[++top]=x;
}
char pop(){
    if(top==-1){
        printf("Stack underflow.\n");
        return '\0';
    }
    return stack[top--];
}
void reverse(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        push(str[i]);
    }
    for(int i=0;i<n;i++){
        str[i]=pop();
    }
}
int main(){
    char ch[50];
    printf("Enter a string to revrse: ");
    scanf("%s",ch);
    reverse(ch);
    printf("Reversed string: %s\n",ch);
    return 0;
}