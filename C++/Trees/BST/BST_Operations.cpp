#include <bits/stdc++.h>
using namespace std;

class BSTNODE {
public:
    int data;
    BSTNODE *left, *right;
    BSTNODE(int ele) {
        data = ele;
        left = right = nullptr;
    }
};

class BST {
public:
    BSTNODE *root;

    BST() {
        root = nullptr;
    }

    BSTNODE *insertNode(BSTNODE *node, int ele);
    BSTNODE *deleteNode(BSTNODE *node, int ele);
    BSTNODE *searchNode(BSTNODE *node, int ele);
    BSTNODE *minValueNode(BSTNODE *node);
    void inorder(BSTNODE *node);
    void preorder(BSTNODE *node);
    void postorder(BSTNODE *node);
};

BSTNODE *BST::insertNode(BSTNODE *node, int ele) {
    if (node == nullptr) {
        cout << "Successfully inserted.\n";
        return new BSTNODE(ele);
    }

    if (ele < node->data)
        node->left = insertNode(node->left, ele);
    else if (ele > node->data)
        node->right = insertNode(node->right, ele);
    else
        cout << "Element already exists in the BST.\n";

    return node;
}

BSTNODE *BST::minValueNode(BSTNODE *node) {
    BSTNODE *curr = node;
    while (curr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

BSTNODE *BST::deleteNode(BSTNODE *node, int ele) {
    if (node == nullptr) {
        cout << "Cannot find " << ele << " in the BST.\n";
        return node;
    }

    if (ele < node->data)
        node->left = deleteNode(node->left, ele);
    else if (ele > node->data)
        node->right = deleteNode(node->right, ele);
    else {
        if (node->left == nullptr) {
            BSTNODE *temp = node->right;
            cout << "Successfully deleted " << ele << " from BST.\n";
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNODE *temp = node->left;
            cout << "Successfully deleted " << ele << " from BST.\n";
            delete node;
            return temp;
        }

        BSTNODE *temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

BSTNODE *BST::searchNode(BSTNODE *node, int ele) {
    if (node == nullptr || node->data == ele)
        return node;
    if (ele > node->data)
        return searchNode(node->right, ele);
    return searchNode(node->left, ele);
}

void BST::inorder(BSTNODE *node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BST::preorder(BSTNODE *node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::postorder(BSTNODE *node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {
    int x, op;
    BST bst;

    while (true) {
        cout << "\n1.Insert 2.Delete 3.Search 4.Inorder 5.Postorder 6.Preorder 7.Exit\n";
        cout << "Enter your option: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Enter an element to be inserted: ";
                cin >> x;
                bst.root = bst.insertNode(bst.root, x);
                break;
            case 2:
                cout << "Enter the element to be deleted: ";
                cin >> x;
                bst.root = bst.deleteNode(bst.root, x);
                break;
            case 3:
                cout << "Enter the element you want to search: ";
                cin >> x;
                if (bst.searchNode(bst.root, x) == nullptr)
                    cout << "Element not found in the BST.\n";
                else
                    cout << "Element found in the BST.\n";
                break;
            case 4:
                if (bst.root == nullptr)
                    cout << "BST is empty.\n";
                else {
                    cout << "Inorder traversal: ";
                    bst.inorder(bst.root);
                    cout << endl;
                }
                break;
            case 5:
                if (bst.root == nullptr)
                    cout << "BST is empty.\n";
                else {
                    cout << "Postorder traversal: ";
                    bst.postorder(bst.root);
                    cout << endl;
                }
                break;
            case 6:
                if (bst.root == nullptr)
                    cout << "BST is empty.\n";
                else {
                    cout << "Preorder traversal: ";
                    bst.preorder(bst.root);
                    cout << endl;
                }
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}
