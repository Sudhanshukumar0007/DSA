#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
int front=-1,rear=-1;
int queue[MAX_SIZE];
void enqueue(int x){
    if(rear==MAX_SIZE-1){
        printf("Queue is overflow.\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    queue[++rear]=x;
    printf("Enqueued : %d \n",x);
}
void dequeue(){
    if(front==-1 || front>rear){
        printf("Queue is empty.\n");
        return;
    }
    int value=queue[front++];
    printf("Dequeued value : %d",value);
    if(front>rear){
        front=rear=-1;
    }
}
void display(){
    if(front==-1 || front>rear){
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements of queue are : ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void isEmpty(){
    if(front==-1 || front>rear){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue is not empty.\n");
}
void size() {
    if (front == -1 || front > rear) {
        printf("Size of the queue = 0\n");
    } else {
        printf("Size of the queue = %d\n", rear - front + 1);
    }
}
int main() {
    int op, x;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Is Empty  5.Size  6.Exit\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                isEmpty();
                break;

            case 5:
                size();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}