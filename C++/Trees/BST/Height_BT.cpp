#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
// WE are building the tree from level order traversal of the tree that is why weare pushing left and right into tree simultaneously
Node *buildTree(vector<string>&nodes){
    if(nodes.empty() || nodes[0]=="null"){
        return nullptr;
    }
    Node *root = new Node(stoi(nodes[0]));
    queue<Node *>q;
    q.push(root);

    int i=1;
    while(!q.empty() && i<nodes.size()){
        Node *current = q.front();
        q.pop();
        if(i<nodes.size() && nodes[i]!="null"){
            current->left = new Node(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;
        if(i<nodes.size() && nodes[i]!="null"){
            current->right = new Node(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}
int height(Node *root){
    if(root==nullptr){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int main(){
    int n;
    cin>>n;
    vector<string>nodes(n);
    for(int i=0;i<n;i++){
        cin>>nodes[i];
    }
    Node *root =  buildTree(nodes);
    cout<<height(root)<<endl;
    return 0;
}