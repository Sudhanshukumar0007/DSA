#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null") return NULL;

    Node* root = new Node(stoi(arr[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* cur = q.front();
        q.pop();

        // left child
        if (i < arr.size() && arr[i] != "null") {
            cur->left = new Node(stoi(arr[i]));
            q.push(cur->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != "null") {
            cur->right = new Node(stoi(arr[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int maxLeafToLeaf(Node* root, int &ans) {
   if(!root) return INT_MIN;
   if(!root->left && !root->right) return root->val;

   int left=maxLeafToLeaf(root->left,ans);
   int right=maxLeafToLeaf(root->right,ans);

   if(root->left && root->right){
    ans = max(ans, left+right+root->val);
   }

   return root->val+max(left,right);
}

int main() {
    vector<string> arr;
    string x;

    while (cin >> x) {
        if (x == "-1") break;
        arr.push_back(x);
    }

    Node* root = buildTree(arr);

    int ans = INT_MIN;
    int temp = maxLeafToLeaf(root, ans);

    cout << ans << endl;
    return 0;
}
