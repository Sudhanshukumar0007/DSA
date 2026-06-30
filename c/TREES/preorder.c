#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE;

// Create tree
NODE create() {
    NODE newNode;
    int val;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &val);

    if (val == -1) {
        return NULL;
    }

    newNode = (NODE) malloc(sizeof(struct node));
    newNode->data = val;

    printf("Enter left child of %d:\n", val);
    newNode->left = create();

    printf("Enter right child of %d:\n", val);
    newNode->right = create();

    return newNode;
}

// Preorder traversal
void PreOrder(NODE root) {
    if (root == NULL) return;
     printf("%d ", root->data);
    PreOrder(root->left);
   PreOrder(root->right);
}
int main() {
    NODE root = NULL;
    root = create();

    printf("\nPreOrder Traversal:\n");
    PreOrder(root);
    return 0;
}
