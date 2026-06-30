#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// forward declaration
int height(Node *root, int &diameter);

Node* BuildTree(const string &treeStr) {
    if(treeStr.empty()) return nullptr;

    stringstream ss(treeStr);
    string val;
    ss>>val;
    Node *root=new Node(stoi(val));
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        
        if(!(ss>>val)) break;
        if(val!="N"){
            curr->left = new Node(stoi(val));
            q,push(curr->left);
        }
        if(!(ss>>val)) break;
        if(val!="N"){
            curr->right = new Node(stoi(val));
            q.push(curr->right);
        }
    }
    return root;

}

int height(Node *root, int &diameter) {
    if(!root) return 0;
    int leftH = height(root->left, diameter);
    int rightH = height(root->right, diameter);
    diameter = max(diameter, leftH + rightH); // path length in edges
    return 1 + max(leftH, rightH);
}

int diameterOfBinaryTree(const string &treeStr) {
    Node *root = BuildTree(treeStr);
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    // Read full line (level-order) like: 1 2 3 4 5 N 6
    string treeStr;
    if(!getline(cin, treeStr) || treeStr.empty()){
        cerr << "Provide level-order tree string (use 'N' for null). Example:\n";
        cerr << "1 2 3 4 5 N 6\n";
        return 1;
    }

    cout << diameterOfBinaryTree(treeStr) << endl;
    return 0;
}
