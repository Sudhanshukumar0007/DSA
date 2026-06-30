#include <stdlib.h>
#include <stdio.h>

struct queue {
    int data;
    struct queue *next;
};
typedef struct queue *Q;

Q front = NULL, rear = NULL;

void enqueue(int x) {
    Q temp = (Q) malloc(sizeof(struct queue));
    if (temp == NULL) {
        printf("Queue is overflow.\n");
        return;
    }
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("Successfully inserted.\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is underflow.\n");
        return;
    }

    printf("Dequeued value = %d\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
}

void size() {
    Q temp = front;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Size = %d\n", count);
}

void isEmpty() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n"); 
    } else {
        Q temp = front;
        printf("Elements in the queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int op, x;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n");
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
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}
