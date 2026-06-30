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

int height(Node *root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

pair<int,int> diameterFast(Node *root) {
    if (!root) return {0, 0};

    auto left = diameterFast(root->left);
    auto right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    int diameter = max(op1, max(op2, op3));
    int height = max(left.second, right.second) + 1;

    return {diameter, height};
}

int diameter(Node *root) {
    return diameterFast(root).first;
}

pair<bool,int> checkBalancedFast(Node *root) {
    if (!root) return {true, 0};

    auto left = checkBalancedFast(root->left);
    auto right = checkBalancedFast(root->right);

    bool balanced = left.first &&
                    right.first &&
                    abs(left.second - right.second) <= 1;

    int height = max(left.second, right.second) + 1;

    return {balanced, height};
}

bool checkBalanced(Node *root) {
    return checkBalancedFast(root).first;
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
pair<bool, int> solve(Node* root) {
        if (!root) return {true, 0};

        if (!root->left && !root->right)
            return {true, root->data};

        auto left = solve(root->left);
        auto right = solve(root->right);

        bool isSum = left.first && right.first &&
                     (root->data == left.second + right.second);

        int totalSum = root->data + left.second + right.second;

        return {isSum, totalSum};
    }
bool isSumTree(Node* root) {
        return solve(root).first;
    }
bool isIdentical(Node* r1, Node* r2) {
        // code here
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        return (r1->data==r2->data) && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
int main() {
    cout << "Enter tree data (-1 for NULL):\n";
    Node* root = buildTree();

    cout << "\nLevel Order Traversal:\n";
    levelOrder(root);

    cout << "\nHeight of the tree: " << height(root) << endl;
    cout << "Diameter of the tree: " << diameter(root) << endl;
    cout << "Is Balanced: " << (checkBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}
