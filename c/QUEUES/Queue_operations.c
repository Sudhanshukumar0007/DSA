#include <stdio.h>
#include <stdlib.h>

#define queue_max_size 20

int queue[queue_max_size];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == queue_max_size - 1) {
        printf("Queue is overflow.\n");
        return;
    }

    if (front == -1) {
        front = 0;  // initialize front
    }

    queue[++rear] = x;
    printf("Enqueued: %d\n", x);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    int value = queue[front++];
    printf("Dequeued: %d\n", value);

    // Reset front and rear if queue becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

void isEmpty() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

void size() {
    if (front == -1 || front > rear) {
        printf("Size of the queue = 0\n");
    } else {
        printf("Size of the queue = %d\n", rear - front + 1);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements of Queue are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
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
