#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie* arr[26];
    bool isEndOfWord;

    Trie() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            arr[i] = NULL;
    }

    // Insert a word into the Trie
    void insert(Trie* root, string word) {
        Trie* current = root;

        for (char ch : word) {
            int index = ch - 'a';   // FIXED: should be 'a', not '0'

            if (current->arr[index] == NULL) {
                current->arr[index] = new Trie();
            }
            current = current->arr[index];
        }

        current->isEndOfWord = true;
    }

    // Search complete word
    bool search(Trie* root, string word) {
        Trie* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->arr[index] == NULL)
                return false;

            curr = curr->arr[index];
        }

        return curr->isEndOfWord;
    }

    // Check if any word starts with given prefix
    bool startsWith(Trie* root, string prefix) {
        Trie* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (curr->arr[index] == NULL)
                return false;

            curr = curr->arr[index];
        }

        return true;
    }
};

int main() {
    Trie* root = new Trie();

    root->insert(root, "cat");
    root->insert(root, "cap");
    root->insert(root, "dog");

    cout << root->search(root, "cat") << endl;      // 1
    cout << root->search(root, "car") << endl;      // 0
    cout << root->startsWith(root, "ca") << endl;   // 1
    cout << root->startsWith(root, "do") << endl;   // 1
    cout << root->startsWith(root, "da") << endl;   // 0

    return 0;
}
