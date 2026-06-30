#include<iostream>
using namespace std ;
class NODE{
    public:
    int data;
    NODE *next;
    NODE(int data){
        this->data=data;
        this->next=nullptr;
    }
};
void InsertAtHead(NODE* &head,int x){
    //Creating the node
    NODE *temp=new NODE(x);
    temp->next=head;
    head=temp;
}
void InsertAtTail(NODE *&tail,int x){
    NODE *temp=new NODE(x);
    tail->next=temp;
    tail=temp;
}
void InsertAtPosition(NODE* &tail,NODE *&head,int x,int pos){
    if(pos==1){
        InsertAtHead(head,x);
        return;
    }
    int cnt=1;
    NODE *curr=head;
    while(curr !=nullptr && cnt<pos-1){
        curr=curr->next;
        cnt++;
    }
    if(curr->next==nullptr){
        InsertAtTail(tail,x);
        return;
    }
    NODE *nodeToInsert=new NODE(x);
    nodeToInsert->next=curr->next;
    curr->next=nodeToInsert;

}
void print(NODE *&head){
    NODE*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
void deleteNode(NODE*& head, int val) {
    if(head==nullptr) return;
    //if we have to delete head
    if(head->data==val){
        head=head->next;
        return;
    }
    NODE *curr=head;
    //Traverse till the node and then delete it if its not null if curr becomes null meaning we didnt found the element 
    while(curr->next!=nullptr && curr->next->data!=val){
        curr=curr->next;
    }
    if(curr->next!=nullptr){
        NODE *temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
    }
    else{
        cout<<"element not found.\n";
    }
}
void deletAtPosition(NODE *&head,int pos){
    if(head==nullptr) return;
    if(pos==1){
        NODE *temp=head;
        head=head->next;
        delete temp;
        return;
    }
    int cnt=1;
    NODE *curr=head;
    while(curr!=nullptr && cnt<pos-1){
        curr=curr->next;
        cnt++;
    }
    if(curr!=nullptr && curr->next!=nullptr){
        NODE *Nodetodelete=curr->next;
        curr->next=curr->next->next;
        delete Nodetodelete;
    }else{
        cout<<"position does not exist.so deletion not possible.\n";
    }
}
int length(NODE* &head){
    int cnt=0;
    NODE *curr=head;
    while(curr!=nullptr){
        cnt++;
        curr=curr->next;
    }
    return cnt;
}
void removeDuplicates(NODE *head){
    if(head==nullptr) return;
    NODE *curr=head->next;
    NODE *prev=head;
    while(curr!=NULL){
        if(curr->data==prev->data){
            NODE *temp=curr;
            curr=curr->next;
            prev->next=curr;
            delete temp;
        }else{
            prev=prev->next;
            curr=curr->next;
        }
    }
}
int main(){
    NODE * node1=new NODE(10);
    NODE *head=node1;
    NODE *tail=node1;
    InsertAtTail(tail,20);
    InsertAtTail(tail,20);
    InsertAtTail(tail,30);
    InsertAtTail(tail,40);
    InsertAtTail(tail,40);
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    print(head);
    removeDuplicates(head);
    print(head);
    return 0 ;
}