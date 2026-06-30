#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node *left,*right;
	Node(int ele){
		data=ele;
		left=right=nullptr;
	}
};
Node *buildTree(vector<string>&str){
	if(str.empty() || str[0]=="null")
		return nullptr;
	Node *root = new Node(stoi(str[0]));
	queue<Node*>q;
	q.push(root);
	int i=1;
	while(!q.empty()){
		Node *curr = q.front();
		q.pop();
		if(i<str.size() && str[i]!="null"){
			curr->left = new Node(stoi(str[i]));
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
void inorder(Node *root,vector<int>&v){
	if(root==nullptr) return;
	inorder(root->left,v);
	v.push_back(root->data);
	inorder(root->right,v);
}
int main(){
	bool flag = true;
	vector<string>str;
	while(flag){
		string x;
		cin >> x;
		if(x=="-1"){
			flag=false;
		}else{
			str.push_back(x);
		}
	}
	int k;
	cin>>k;
	Node *root=buildTree(str);
	vector<int>v;
	inorder(root,v);
	cout<<v[k-1]<<endl;
	return 0;
}