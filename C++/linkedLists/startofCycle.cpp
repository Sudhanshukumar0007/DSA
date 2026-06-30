#include<iostream>
using namespace std ;
class node{
    public:
    int data;
    node *next;
    node(int x){
        this->data=x;
        this->next=nullptr;
    }
};
bool detectLoop(node *head){
    if(head==nullptr || head->next==nullptr) return false;
    node *fast=head;
    node *slow=head;
    while(fast!=nullptr && slow!=nullptr){
        fast=fast->next;
        if(fast!=nullptr){
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void InsertAtHead(node* &head,int x){
    //Creating the node
    node *temp=new node(x);
    temp->next=head;
    head=temp;
}
void InsertAtTail(node *&tail,int x){
    node *temp=new node(x);
    tail->next=temp;
    tail=temp;
}
node *Startpoint(node *head){
    
}
int main(){
    node *node1=new node(10);
    node *head=node1;
    node *tail=node1;
    InsertAtTail(tail,20);
    InsertAtTail(tail,30);
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    InsertAtTail(tail,60);
    InsertAtTail(tail,70);
    tail->next=node1->next->next;
    if(detectLoop(head)){
        cout<<"Loop detected.\n";
    }else{
        cout<<"Loop not detected.\n";
    }
    return 0 ;
}