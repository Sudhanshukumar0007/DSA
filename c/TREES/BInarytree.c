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

// Inorder traversal
void inorder(NODE root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Pretty tree print (rotated 90 degrees)
void printTree(NODE root, int space) {
    if (root == NULL) return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

int main() {
    NODE root = NULL;
    root = create();

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\n\nTree Structure (rotated 90 degrees):\n");
    printTree(root, 0);

    return 0;
}
