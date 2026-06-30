#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define STACK_MAX_SIZE 20
char stack[STACK_MAX_SIZE];

int top=-1;

int isEmpty(){
    if(top==-1) return 1;
    else return 0;
}

void push(char x){
    if(top==STACK_MAX_SIZE-1){
        return ;
    }
    else{
        top++;
        stack[top]=x;
    }
}

char pop(){
    if(top==-1){
        return '\0';
    }
    else{
        return stack[top--];
    }
}

int priority(char x){
    if(x=='(') return 0;
    else if(x=='+' || x=='-') return 1;
    else return 2;
}

void convertInfix(char *e){
    char output[100];
    int k=0;
    for(int i=0;e[i]!='\0';i++){
        char ch=e[i];
        if(!(isalnum(ch) || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(' || ch==')' || ch=='%')){
            printf("Invalid symbol in infix expression. Only alphanumeric and{'+','-','*','/','%%'} are allowed.\n");
            return;
        }
        if(isalnum(ch)){
            output[k++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(!isEmpty() && stack[top]!='('){
                output[k++]=pop();
            }
            if(!isEmpty() && ch=='('){
                pop();
            }
            else{
                printf("Invalid infix expression : unbalanced parenthesis.\n");
                return;
            }
        }
        else{
            while(!isEmpty() && priority(stack[top])>=priority(ch)){
                output[k++]=pop(ch);
            }push(ch);
        }
    }

    while(!isEmpty()){
        if(stack[top]=='('){
            printf("Invalid infix expression : unbalanced parenthesis.\n");
            return;
        }
        output[k++]=pop();
    }
    output[k]='\0';
    printf("Postfix expression : %s\n",output);
}

int main() {
	char exp[20];
	char *e, x;
	printf("Enter the expression : ");
	scanf("%s",exp);
	e = exp;
	convertInfix(e);
}