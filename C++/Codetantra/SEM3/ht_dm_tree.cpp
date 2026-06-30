#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int x){
        data=x;
        left=right=nullptr;
    }
};
Node *buildTree(vector<string>&nodes){
    if(nodes.empty() || nodes[0]=="null"){
        return nullptr;
    }
    Node *root = new Node(stoi(nodes[0]));
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<nodes.size()){
        Node *curr=q.front();
        q.pop();
        if(i<nodes.size() && nodes[i]!="null"){
            curr->left=new Node(stoi(nodes[i]));
            q.push(curr->left);
        }i++;
        if(i<nodes.size() && nodes[i]!="null"){
            curr->right=new Node(stoi(nodes[i]));
            q.push(curr->right);
        }i++;
    }
    return root;
}
int height(Node *root){
    if(root==nullptr) return 0;
    return 1+max(height(root->left),height(root->right));
}
int height_d(Node *root,int &diameter){
    if(root==nullptr) return 0;
    int left=height_d(root->left,diameter);
    int right=height_d(root->right,diameter);
    diameter =max(left+right,diameter);

    return 1+max(left,right);
}
int diameter(Node *root){
    int diameter=0;
    height_d(root,diameter);
    return diameter;
}
int main(){
    int n;
    cin>>n;
    vector<string>nodes(n);
    for(int i=0;i<n;i++){
        cin>>nodes[i];
    }
    Node *root = buildTree(nodes);
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
    return 0;
}