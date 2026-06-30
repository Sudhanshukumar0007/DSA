#include<iostream>
using namespace std ;
class Node{
    public:
    int data;
    Node* next;
    Node *prev;
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
void InsertAtHead(Node *&head,Node *&tail,int data){
    Node *newnode=new Node(data);
    if(head==nullptr){
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode; 
}
void InsertAtTail(Node* &head,Node *&tail,int data){
    Node *newNode=new Node(data);
    if(tail==nullptr){
        tail=newNode;
        head=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}
void InsertAtPosition(Node *&head,Node *&tail, int data, int pos) {
    Node *newNode = new Node(data);

    // Case 1: Empty list
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Case 2: Insert at head
    if (pos == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Traverse to (pos-1)th node
    Node *curr = head;
    int count = 1; // since head is position 1
    while (curr != nullptr && count < pos - 1) {
        curr = curr->next;
        count++;
    }

    // If position is beyond list length → insert at end
    if (curr == nullptr) return;

    // Case 3: Normal insertion in middle or end
    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next != nullptr) {  // if not inserting at tail
        curr->next->prev = newNode;
    }
    else{
        tail=newNode;
    }

    curr->next = newNode;
}
void print(Node* &head){
    Node *curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}
int length(Node *&head){
    Node *curr=head;
    int cnt=0;
    while (curr!=nullptr)
    {
        cnt++;
        curr=curr->next;
    }
    return cnt;
}
void DeleteNodeByValue(Node *&head,Node *&tail,int val){
    if(head==nullptr) return;
    if(head->data==val){
        Node *temp=head;
        head=head->next;
        if(head!=nullptr){
        head->prev=nullptr;
        }
        delete temp;
        return;
    }
    Node *curr=head;
    while(curr->next!=nullptr && curr->next->data!=val){
        curr=curr->next;
    }
    if(curr->next!=nullptr){
        Node *temp=curr->next;
        curr->next=temp->next;
        if(temp->next !=nullptr){
        temp->next->prev=curr;
        }
        if(temp==tail){
            tail=curr;
        }
        delete temp;
    }
    else{
        cout<<"Element not found.\n";
    }
}
void DeleteNodeAtposition(Node *&head,Node *&tail,int pos){
    if(head==nullptr) return;
    if(pos==1){
        Node* temp=head;
        head=head->next;
        if(head!=nullptr){
            head->prev=nullptr;
        }
        delete temp;
        return;
    }
    Node *curr=head;
    int count=1;
    while(curr!=nullptr && count<pos-1){
        curr=curr->next;
        count++;
    }
    if(curr==nullptr || curr->next ==nullptr){
        return;
    }
    Node*temp=curr->next;
    curr->next=temp->next;
    if(temp->next!=nullptr){
        temp->next->prev=curr;
    }else{
        tail=curr;
    }
    delete temp;
}
void PrintReverse(Node *&tail){
    Node*curr=tail;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->prev;
    }
    cout<<endl;
}
int main(){
    Node *node1=new Node(50);
    Node* head=node1;
    Node *tail=node1;
    InsertAtHead(head,tail,40);
    InsertAtHead(head,tail,30);
    InsertAtHead(head,tail,20);
    InsertAtHead(head,tail,10);
    print(head);
    InsertAtTail(head,tail,60);
    InsertAtTail(head,tail,70);
    InsertAtTail(head,tail,80);
    InsertAtTail(head,tail,90);
    print(head);
    InsertAtPosition(head,tail,0,1);
    InsertAtPosition(head,tail,100,11);
    InsertAtPosition(head,tail,110,12);
    print(head);
    cout<<"Length of the linked list is: "<<length(head)<<endl;
    DeleteNodeByValue(head,tail,50);
    DeleteNodeByValue(head,tail,60);
    DeleteNodeByValue(head,tail,70);
    print(head);
    DeleteNodeAtposition(head,tail,1);
    DeleteNodeAtposition(head,tail,5);
    DeleteNodeAtposition(head,tail,9);
    print(head);
    PrintReverse(tail);
    return 0 ;
}