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
int main(){
    NODE * node1=new NODE(30);
    NODE *head=node1;
    NODE *tail=node1;
    InsertAtHead(head,20);
    InsertAtHead(head,10);
    // print(head);
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    // print(head);
    InsertAtPosition(tail,head,60,6);
    print(head);
    cout<<"Head->"<<head->data<<endl;
    cout<<"Tail->"<<tail->data<<endl;
    deleteNode(head,40);
    print(head);
    deleteNode(head,10);
    print(head);
    deleteNode(head,60);
    print(head);
    deletAtPosition(head,2);
    print(head);
    cout<<"Length of the given linked list is : "<<length(head)<<endl;
    return 0 ;
}