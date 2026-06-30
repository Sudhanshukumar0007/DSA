#include<iostream>
using namespace std ;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
void insertNode(Node *&tail,int element,int d){
    if(tail==nullptr){
        Node *newNode=new Node(d);
        tail=newNode;
        tail->next=newNode;
    }else{
        Node *curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node *temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
    
}
void print(Node *tail){
    Node *temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail != temp);
}
void deleteNode(Node* &tail, int val) {
    if (tail == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* prev = tail;
    Node* curr = prev->next; // first node

    // Search for value
    while (curr->data != val) {
        if (curr == tail) { // full circle checked
            cout << "Value not found.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // Case 1: Single node
    if (curr == prev) {
        tail = nullptr;
        delete curr;
        return;
    }

    // Case 2: More than one node
    prev->next = curr->next;

    // If deleting tail
    if (curr == tail) {
        tail = prev;
    }

    delete curr;
}

int main(){
    Node *tail=nullptr;
    insertNode(tail,5,1);
    insertNode(tail,1,2);
    insertNode(tail,2,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    insertNode(tail,5,6);
    insertNode(tail,6,7);
    insertNode(tail,7,8);
    deleteNode(tail,4);
    deleteNode(tail,1);
    deleteNode(tail,7);
    print(tail);
    return 0 ;
}