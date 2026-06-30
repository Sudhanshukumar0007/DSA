#include<bits/stdc++.h>
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
Node *insert(Node *node,int x){
    if(node==nullptr){
        return new Node(x);
    }
    if(x<node->data){
        node->left = insert(node->left,x);
    }else{
        node->right = insert(node->right,x);
    }
}
Node *findLCA(Node *root,int n1,int n2){
    if(root==nullptr) return nullptr;
    if(n1<root->data && n2<root->data)
        return findLCA(root->left,n1,n2);
    if(n1>root->data && n2>root->data)
        return findLCA(root->right,n1,n2);
    return root;
}
int main(){
    int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	Node *root=nullptr;
    int n1,n2;
    cin>>n1>>n2;

    for(int val:arr){
		root = insert(root,val);
	}
	Node *lca =findLCA(root,n1,n2);
	if(lca)
		cout<<lca->data<<endl;
	else
		cout<<"No common ancestor found"<<endl;
    return 0;
}
