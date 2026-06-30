#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
typedef struct node * NODE;
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
void inorder(NODE root){
    if (root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(NODE root){
    if (root==NULL)  return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(NODE root){
    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main() {
    NODE root = NULL;
    root = create();

    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\n Preorder Traversal:\n");
    preorder(root);
    printf("\nPostorder Traversal:\n");
    postorder(root);
    return 0;
}
