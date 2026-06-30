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

    if (data == -1) return nullptr;

    Node* root = new Node(data);

    cout << "Enter data for LEFT of " << root->data << " : ";
    root->left = buildTree();

    cout << "Enter data for RIGHT of " << root->data << " : ";
    root->right = buildTree();

    return root;
}
void levelOrder(Node *root) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;
            level[index] = curr->data;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        res.push_back(level);
        leftToRight = !leftToRight;
    }

    return res;
}
void leftTraversal(Node *root,vector<int>&ans){
    if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
        return;
    }
    ans.push_back(root->data);
    if(root->left)
        leftTraversal(root->left,ans);
    else
        leftTraversal(root->right,ans);
}
void rightTraversal(Node *root,vector<int>&ans){
    if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
        return;
    }
    if(root->right){
        rightTraversal(root->right,ans);
    }else{
        rightTraversal(root->left,ans);
    }
    ans.push_back(root->data);
}
void leafTraversal(Node *root,vector<int>&ans){
    if(root==nullptr) return;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
}
vector<int>boundaryTraversal(Node *root){
   vector<int>ans;
   if(root==nullptr){
    return ans;
   }
   ans.push_back(root->data);
   leftTraversal(root->left,ans);

   leafTraversal(root->left,ans);
   leafTraversal(root->right,ans);

   rightTraversal(root->right,ans);
   
   return ans;

}
vector<vector<int>> verticalOrder(Node *root) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int,int>>> q;
        vector<vector<int>> ans;

        if (!root) return ans;

        // node, {horizontal distance, level}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            nodes[hd][level].push_back(frontNode->data);

            if (frontNode->left)
                q.push({frontNode->left, {hd - 1, level + 1}});

            if (frontNode->right)
                q.push({frontNode->right, {hd + 1, level + 1}});
        }

        // Build answer
        for (auto &i : nodes) {
            vector<int> col;
            for (auto &j : i.second) {
                for (int val : j.second) {
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }

        return ans;
    }
vector<int> topView(Node *root) {
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node *,int>temp = q.front();
            q.pop();
            Node *frontnode = temp.first;
            int hd = temp.second;
            if(mp.find(hd)==mp.end()){
                mp[hd] = frontnode->data;
            }
            if(frontnode->left){
                q.push({frontnode->left,hd-1});
            }if(frontnode->right){
                q.push({frontnode->right,hd+1});
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
int main() {
    cout << "Enter tree data (-1 for NULL):\n";
    Node* root = buildTree();

    cout << "\nLevel Order Traversal:\n";
    levelOrder(root);

    cout << "\nZigzag Level Order Traversal:\n";
    vector<vector<int>> zigzag = zigzagLevelOrder(root);

    for (auto &level : zigzag) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<"\n Boundary traversal:\n";
    vector<int>boundary = boundaryTraversal(root);
    for(int i:boundary){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
