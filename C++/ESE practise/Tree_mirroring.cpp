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
bool isMirror(Node *a,Node *b){
    if(a==nullptr && b==nullptr) return true;
    if(a==nullptr || b==nullptr) return false;
    return (a->data==b->data) && isMirror(a->left,b->right) && isMirror(a->right,b->left);
}
int mirror(Node *root){
    if(root==nullptr) return 1;
    return isMirror(root->left,root->right)?1:0;
}
int main(){
	vector<string>str;
	bool flag=true;
	while(flag){
		string x;
		cin>>x;
		if(x=="-1"){
			flag=false;
		}else{
			str.push_back(x);
		}
	}
	Node *root=buildTree(str);
	cout<<mirror(root);
	return 0;
}