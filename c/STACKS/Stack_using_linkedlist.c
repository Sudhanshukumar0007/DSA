#include <stdio.h>
#include <stdlib.h>
struct stack{
	int data;
	struct stack *next;
};
typedef struct stack *stk;
stk top=NULL;

void push(int x){
	stk temp=(stk) malloc(sizeof(struct stack));
	if(temp==NULL){
		printf("Stack is overflow.\n");
	}else{
	temp->data=x;
	temp->next=top;
	top=temp;
	printf("Successfully pushed.\n");
}
}

void pop(){
	if(top==NULL){
		printf("Stack is underflow.\n");
		return;
	}
	else{
		stk temp=top;
		top=top->next;
		printf("Popped value = %d \n",temp->data);
		free(temp);
	}
}

void peek(){
	if(top==NULL){
		printf("Stack is empty.\n");
	}
	else{
		printf("Peek value = %d \n",top->data);
	}
}

void isEmpty(){
	if(top==NULL){
		printf("Stack is empty.\n");
	}
	else{
		printf("Stack is not empty.\n");
	}
}

void display(){
	if(top==NULL){
		printf("Stack is empty.\n");
		return;
	}
	else{
		printf("Elements of stack are\n");
		stk temp=top;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}printf("\n");
	}
}


int main() {
	int op, x;
	while(1) {	
		printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				peek();
				break;
			case 6: 
				exit(0);
		}
	}
}