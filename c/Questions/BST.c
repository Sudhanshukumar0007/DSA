#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *BSTNODE;
BSTNODE newNodeInBST(int val){
    BSTNODE newNode=(BSTNODE) malloc(sizeof(struct node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
} 
BSTNODE InsertInBST(BSTNODE root,int ele){
    BSTNODE newNode=newNodeInBST(ele);
    if(root==NULL) {
        printf("Successfully inserted.\n");
        return newNode;
    }
    if(ele<root->data){
        root->left=InsertInBST(root->left,ele);
    }
    else if(ele>root->data){
        root->right=InsertInBST(root->right,ele);
    }
    else{
        printf("Element already presnt in BST\n");
    }
    return root;
}
void inorder(BSTNODE root){
    if (root==NULL) return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main() {
    int x, op;
    BSTNODE root = NULL;

    while (1) {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n2. Inorder Traversal\n3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter an element to be inserted: ");
                scanf("%d", &x);
                root = InsertInBST(root, x);
                break;

            case 2:
                if (root == NULL) {
                    printf("Binary Search Tree is empty.\n");
                } else {
                    printf("Inorder Traversal of BST: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
