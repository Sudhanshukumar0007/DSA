#include<bits/stdc++.h>
using namespace std;
class NODE{
public:
	int data;
	NODE *left,*right;
	NODE(int val){
		data = val;
		left = right =nullptr;
	}
};
NODE *insert(NODE *root,int ele){
	if(root==nullptr){
		return new NODE(ele);
	}
	if(ele<root->data){
		root->left = insert(root->left,ele);
	}else{
		root->right = insert(root->right,ele);
	}return root;
}
NODE *findLCA(NODE *root,int n1,int n2){
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
	NODE *root=nullptr;
	int n1;
	cin>>n1;
	int n2;
	cin>>n2;
	for(int val:arr){
		root = insert(root,val);
	}
	NODE *lca =findLCA(root,n1,n2);
	if(lca)
		cout<<lca->data<<endl;
	else
		cout<<"No common ancestor found"<<endl;
	return 0;
}