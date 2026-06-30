#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// insert into BST
Node* insertBST(Node* root, int val) {
    if (root == nullptr) return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// BFS Traversal (Level Order)
void BFS(Node* root) {
   if(!root) return ;
   queue<Node *>q;
   q.push(root);
   bool first = true;
   while(!q.empty()){
    Node *curr=q.front();
    q.pop();

    if(!first) cout<<" ";
    cout<<curr->data<<" ";

    if(curr->left) q.push(curr->left);
    if(curr->right) q.push(curr->right);
   }
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    BFS(root);
    return 0;
}
