#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
typedef struct node * BSTNODE;
BSTNODE newNodeInBST(int ele){
    BSTNODE newNode=(BSTNODE) malloc(sizeof(struct node));
    newNode->data=ele;
    newNode->left=newNode->right=NULL;
    return newNode;
}
BSTNODE InsertInBST(BSTNODE root,int ele){
    BSTNODE newNode=newNodeInBST(ele);
    if(root==NULL){
        printf("Successfully Inserted.\n");
        return newNode;
    }
    if(ele<root->data){
        root->left=InsertInBST(root->left,ele);
    }
    else if(ele>root->data){
        root->right=InsertInBST(root->right,ele);
    }
    else{
        printf("Element already exists in BST.\n");
    }
    return root;
}
void inorder( BSTNODE root){
    if(root==NULL) return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(BSTNODE root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}  
void postorder(BSTNODE root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
BSTNODE MinvalNode(BSTNODE root){
    BSTNODE current=root;
    while(current && current->left!=NULL){
        current=current->left;
    }
    return current;
}
BSTNODE SearchInBST(BSTNODE root, int x) {
    if (root == NULL || root->data == x)
        return root;
    if (x < root->data)
        return SearchInBST(root->left, x);
    else
        return SearchInBST(root->right, x);
}

BSTNODE deleteNodeInBST(BSTNODE root,int ele){
    if(root==NULL){
        printf("Cannot find element in BST.\n");
        return root;
    }
    if(ele<root->data){
        root->left=deleteNodeInBST(root->left,ele);
    }
    else if(ele>root->data){
        root->right=deleteNodeInBST(root->right,ele);
    }
    else{
        if(root->left==NULL){
            BSTNODE temp=root->right;
            free(root);
            printf("Deleted %d from binary search tree.\n",ele);
            return temp;
        }
        else if(root->right==NULL){
            BSTNODE temp=root->left;
            free(root);
            printf("Deleted %d from Binary Search tree.\n",ele);
            return temp;
        }
         BSTNODE temp=MinvalNode(root->right);
            root->data=temp->data;
            root->right=deleteNodeInBST(root->right,temp->data);
    }
    return root;
}
int main() {
    int x, op;
    BSTNODE root = NULL;

    while (1) {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search an element\n");
        printf("6. Delete an element\n");
        printf("7. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter an element to be inserted: ");
                scanf("%d", &x);
                root = InsertInBST(root, x);
                break;

            case 2:
                if (root == NULL)
                    printf("Binary Search Tree is empty.\n");
                else {
                    printf("Inorder Traversal of BST: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Binary Search Tree is empty.\n");
                else {
                    printf("Preorder Traversal of BST: ");
                    preorder(root);  // You will implement this
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Binary Search Tree is empty.\n");
                else {
                    printf("Postorder Traversal of BST: ");
                    postorder(root);  // You will implement this
                    printf("\n");
                }
                break;

            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &x);
                if (SearchInBST(root, x))  // You will implement this
                    printf("Element %d found in the BST.\n", x);
                else
                    printf("Element %d not found in the BST.\n", x);
                break;

            case 6:
                printf("Enter the element to delete: ");
                scanf("%d", &x);
                root = deleteNodeInBST(root, x);  // You will implement this
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
