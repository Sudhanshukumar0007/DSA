#include<bits/stdc++.h>
using namespace std;

class AVLNODE{
    public:
    int data;
    AVLNODE *left,*right;
    int ht;
};

class AVLTree{
    public:               // ← you forgot this (methods were private)
    AVLNODE *root;
    AVLTree(){
        root = nullptr;
    }

    int height(AVLNODE *root);
    AVLNODE *createNode(int x);
    AVLNODE *minValueNode(AVLNODE *root);
    int balanceFactor(AVLNODE *root);
    int max(int a,int b);
    AVLNODE *rotateLeft(AVLNODE *X);
    AVLNODE *rotateRight(AVLNODE *X);
    AVLNODE *insertNode(AVLNODE *root,int x);
    AVLNODE *deleteNode(AVLNODE *root,int x);
    AVLNODE *searchNode(AVLNODE *root,int x);

    void inorder(AVLNODE *root);
    void preorder(AVLNODE *root);
    void postorder(AVLNODE *root);
};

// ---------- FUNCTIONS -------------

AVLNODE *AVLTree::createNode(int x){
    AVLNODE *temp = new AVLNODE;
    temp->data = x;
    temp->left=temp->right=nullptr;
    temp->ht=1;
    return temp;
}

int AVLTree::height(AVLNODE *root){
    if(root==nullptr) return 0;
    return root->ht;
}

int AVLTree::max(int a,int b){
    return (a > b ? a : b);
}

int AVLTree::balanceFactor(AVLNODE *root){
    if(root==NULL) return 0;
    return height(root->left) - height(root->right);
}

AVLNODE *AVLTree::minValueNode(AVLNODE *root){
    if(root==nullptr) return nullptr;
    AVLNODE *current = root;
    while(current->left != nullptr){
        current = current->left;     // FIXED (you wrote current->next)
    }
    return current;
}

void AVLTree::inorder(AVLNODE *root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<"("<<balanceFactor(root)<<")"<<" ";
    inorder(root->right);
}

void AVLTree::preorder(AVLNODE *root){    // FIXED name
    if(root==nullptr) return;
    cout<<root->data<<"("<<balanceFactor(root)<<")"<<" ";
    preorder(root->left);
    preorder(root->right);
}

void AVLTree::postorder(AVLNODE *root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"("<<balanceFactor(root)<<")"<<" ";
}

AVLNODE *AVLTree::rotateLeft(AVLNODE *x){
    AVLNODE *y = x->right;          // FIXED AVNODE→AVLNODE
    AVLNODE *temp = y->left;

    y->left = x;
    x->right = temp;

    x->ht = max(height(x->left), height(x->right)) + 1;
    y->ht = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNODE *AVLTree::rotateRight(AVLNODE *y){
    AVLNODE *x = y->left;
    AVLNODE *temp = x->right;

    x->right = y;
    y->left = temp;

    x->ht = max(height(x->left), height(x->right)) + 1;
    y->ht = max(height(y->left), height(y->right)) + 1;

    return x;
}

AVLNODE *AVLTree::insertNode(AVLNODE *root,int x){
    if(root==NULL){
        cout<<"Successfully inserted.\n";
        return createNode(x);
    }

    if(x < root->data){                     // FIXED ele → x
        root->left = insertNode(root->left,x);
    }
    else if(x > root->data){                // FIXED ele → x
        root->right = insertNode(root->right,x);
    }
    else{
        cout<<"Element "<<x<<" Already present in the AVL tree.\n";
        return root;
    }

    root->ht = 1 + max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    // LL
    if(balance>1 && x < root->left->data)
        return rotateRight(root);

    // LR
    if(balance>1 && x > root->left->data){
        root->left = rotateLeft(root->left);
        return rotateRight(root);           // FIXED (you put rotateRight alone)
    }

    // RR
    if(balance<-1 && x > root->right->data)
        return rotateLeft(root);

    // RL
    if(balance<-1 && x < root->right->data){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

AVLNODE *AVLTree::deleteNode(AVLNODE *root,int ele){
    if(root==NULL){
        cout<<"Cannot find element "<<ele<<" in the AVL tree.so cannot delete.\n";
        return root;
    }

    if(ele < root->data){
        root->left = deleteNode(root->left,ele);
    }
    else if(ele > root->data){
        root->right = deleteNode(root->right,ele);
    }
    else{
        // leaf node
        if(root->left==nullptr && root->right==nullptr){
            cout<<"Deleted "<<ele<<" from the AVL tree.\n";
            delete root;
            root = nullptr;
        }
        else if(root->left==nullptr){
            AVLNODE *temp = root->right;
            cout<<"Deleted "<<ele<<" from the AVL tree.\n";
            delete root;
            root = temp;
        }
        else if(root->right==nullptr){
            AVLNODE *temp = root->left;
            cout<<"Deleted "<<ele<<" from the AVL tree.\n";
            delete root;
            root = temp;
        }
        else{
            AVLNODE *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }

    if(root==nullptr) return root;

    root->ht = 1 + max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    // LL
    if(balance>1 && balanceFactor(root->left)>=0)
        return rotateRight(root);

    // LR
    if(balance>1 && balanceFactor(root->left)<0){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RR
    if(balance<-1 && balanceFactor(root->right)<=0)
        return rotateLeft(root);

    // RL
    if(balance<-1 && balanceFactor(root->right)>0){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

AVLNODE *AVLTree::searchNode(AVLNODE *root,int ele){
    if(root==NULL) return NULL;
    if(ele == root->data) return root;
    else if(ele < root->data)
        return searchNode(root->left,ele);
    else
        return searchNode(root->right,ele);
}

int main(){
    int x,op;
    AVLTree avl;
    while(1){
        cout<<"1.Insert 2.Delete 3.Search 4.Inorder 5.Preorder 6.Postorder 7.Exit\n";
        cout<<"Enter Your option: ";
        cin>>op;
        switch(op){
            case 1 :
                cout<<"Enter an element to be Inserted: ";
                cin>>x;
                avl.root = avl.insertNode(avl.root,x);
                break;
            case 2:
                cout<<"Enter an element to be deleted: ";
                cin>>x;
                avl.root = avl.deleteNode(avl.root,x);
                break;
            case 3:
                cout<<"Enter an element to search: ";
                cin>>x;
                AVLNODE*res = avl.searchNode(avl.root,x);
                if(res){
                    cout<<"Element "<<x<<" found in the AVL tree.\n";
                }else{
                    cout<<"Element "<<x<<" Not found.\n";
                }
                break;
            case 4:
                cout<<"Inorder traversal: ";
                avl.inorder(avl.root);
                break;
            case 5:
                cout<<"Preorder traversal: ";
                avl.preorder(avl.root);
                break;
            case 6:
                cout<<"Postorder Traversal: ";
                avl.postorder(avl.root);
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid option\n";

        }
    }
    return 0;
}
