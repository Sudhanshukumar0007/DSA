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
Node *buildTree(vector<string>str){
    if(str.empty() || str[0]=="null"){
        return nullptr;
    }
    Node *root=new Node(stoi(str[0]));
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(i<str.size() && str[i]!="null"){
            curr->left=new Node(stoi(str[i]));
            q.push(curr->left);
        }
        i++;
        if(i<str.size() && str[i]!="null"){
            curr->right = new Node(stoi(str[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;

}
int height(Node *root){
    if(root==nullptr) return 0;
    return 1+max(height(root->left),height(root->right));
}
int main(){
    int n;
    cin>>n;
    vector<string>str;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        str.push_back(x);
    }
    Node *root = nullptr;
    root = buildTree(str);
    cout<<height(root);
    return true;
}