#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    Node* root = new Node(data);

    cout << "Enter data for LEFT of " << root->data << " : ";
    root->left = buildTree();

    cout << "Enter data for RIGHT of " << root->data << " : ";
    root->right = buildTree();

    return root;
}

void levelOrder(Node *root){
    if(!root){
        cout << "Tree is empty.\n";
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
        Node * curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
        } 
        cout<<endl;
    }
}
void inorder(Node *root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node *root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node* buildFromLevelOrder(string treestr) {
    if (treestr.size() == 0)
        return nullptr;

    stringstream ss(treestr);
    vector<string> nodes;
    string temp;

    while (ss >> temp) {
        nodes.push_back(temp);
    }

    if (nodes[0] == "-1")
        return nullptr;

    Node* root = new Node(stoi(nodes[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();

        // LEFT child
        if (nodes[i] != "-1") {
            curr->left = new Node(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // RIGHT child
        if (i < nodes.size() && nodes[i] != "-1") {
            curr->right = new Node(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}
void countLeafNode(Node *root,int &cnt){
    if(!root) return;
    if(root->left && root->right){
        countLeafNode(root->left,cnt);
        countLeafNode(root->right,cnt);
    }
    else if(root->left || root->right ){
        Node *node = root->left?root->left:root->right;
        countLeafNode(node,cnt);
    }
    else if(!root->left && !root->right){
        cnt++;
    }
}
int main() {
    Node* root = nullptr;
    string line;
    int cnt = 0;
    cout << "Enter tree data (-1 for NULL):\n";
    getline(cin,line);
    root = buildFromLevelOrder(line);
    // root = buildTree();
    levelOrder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    countLeafNode(root,cnt);
    cout<<"There are these many leaf nodes "<<cnt<<endl;
    return 0;
}
