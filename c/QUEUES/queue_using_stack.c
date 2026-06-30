#include <stdlib.h>
#include <stdio.h>
struct stack{
    int data;
    struct stack *next;
};
typedef struct stack *stk;
struct queue{
    stk stack1;
    stk stack2;
};
typedef struct queue*Q;
Q que;

void push(stk* stack ,int x){
    stk temp;
    temp=(stk) malloc(sizeof(struct stack));
    if(temp==NULL){
        printf("Stack is overflow.\n");
        return;
    }
    temp->data=x;
    temp->next=*stack;
    *stack=temp;

}

int pop(stk *stack){
    if(*stack==NULL){
        printf("Stack is empty.\n");
    }
    else{
        stk temp=*stack;
        *stack=temp->next;
        return temp->data;
    }
}

void enqueue(int x){
    push(&(que->stack1), x);
}

void dequeue(){
    if (que->stack1 == NULL && que->stack2 == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    if (que->stack2 == NULL) {
        while (que->stack1 != NULL) {
            int val = pop(&(que->stack1));
            push(&(que->stack2), val);
        }
    }

    int dequeued = pop(&(que->stack2));
    printf("Dequeued value = %d\n", dequeued);
}

void display() {
    stk temp;

    // Check if both stacks are empty
    if (que->stack1 == NULL && que->stack2 == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    // Print stack1 elements (rear to front of the queue)
    temp = que->stack1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Print stack2 elements (front to rear of the queue)
    temp = que->stack2;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Print a newline after displaying the queue elements
    printf("\n");
}

int main() {
    que = (Q)malloc(sizeof(struct queue));
	que->stack1 = NULL;
	que->stack2 = NULL;
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1:
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4: exit(0);
		}
	}
}