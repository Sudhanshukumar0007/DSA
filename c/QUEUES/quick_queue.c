#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front=-1,rear=-1;
void enqueue(int x){
    if(rear==MAX_SIZE-1 && front==0 || front==rear+1){
        printf("Circular queue is overflow.\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear=(rear+1) % MAX_SIZE;
    queue[rear]=x;
    printf("Successfully inserted\n");

}
void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("Circular queue is empty.\n");
    } else {
        printf("Elements in the circular queue: ");
        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (i = front; i < MAX_SIZE; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Circular queue is underflow.\n");
        return;
    }

    printf("Dequeued value = %d\n", queue[front]);

    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

void size() {
    int count;
    if (front == -1 && rear == -1) {
        count = 0;
    } else if (rear >= front) {
        count = rear - front + 1;
    } else {
        count = MAX_SIZE - front + rear + 1;
    }
    printf("Size = %d\n", count);
}

void isEmpty() {
    if (front == -1 && rear == -1) {
        printf("Circular queue is empty.\n");
    } else {
        printf("Circular queue is not empty.\n");
    }
}
int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is empty 5.Size 6.Exit\n");
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
			case 4:
				isEmpty();
				break;
			case 5:
				size();
				break;
			case 6: exit(0);
		}
	}
}