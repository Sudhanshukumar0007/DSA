#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node* buildTree(vector<string> &arr) {
   while(arr.empty() || arr[0]=="null"){
    return nullptr;
   }
   Node *root = new Node(stoi(arr[0]));
   queue<Node *>q;
   q.push(root);
   int i=1;
   while(!q.empty()){
    Node *curr = q.front();
    q.pop();
    if(i<arr.size() && arr[i]!="null"){
        curr->left=new Node(stoi(arr[i]));
        q.push(curr->left);
    }
    i++;
    if(i<arr.size() && arr[i]!="null"){
        curr->right=new Node(stoi(arr[i]));
        q.push(curr->right);
    }
    i++;
   }
   return root;
}

void inorder(Node* root, vector<int> &res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

int main() {
    vector<string> arr;
    string x;

    // read until -1
    while (cin >> x) {
        if (x == "-1") break;
        arr.push_back(x);
    }

    int k;
    cin >> k;

    // build BST from level order
    Node* root = buildTree(arr);

    // inorder = sorted order in BST
    vector<int> sorted;
    inorder(root, sorted);

    cout << sorted[k - 1] << endl;
    return 0;
}