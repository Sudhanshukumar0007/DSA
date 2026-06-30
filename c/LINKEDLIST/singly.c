#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createnode(int value) {  // Ensure function name is consistent
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void traversal(NODE first) {  // Return type changed to void
    NODE temp = first;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    NODE head = createnode(10);   // Function name corrected
    NODE second = createnode(20);
    NODE third = createnode(30);

    // Linking nodes
    head->next = second;
    second->next = third;

    // Traversing the list
    printf("Linked List: ");
    traversal(head);

    return 0;  // Added return statement
}
