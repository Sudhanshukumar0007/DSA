#include<iostream>
#include<map>
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
bool DetectLoop(NODE *head){
    map<NODE*,bool>visited;
    NODE *temp=head;
    while(temp!=nullptr){
        if(visited[temp]==true){
        return 1;
    }
        visited[temp]=true;
        temp=temp->next;
    }
    return 0;
}
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

void print(NODE *&head){
    NODE*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
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
NODE *floyds_cycle(NODE *head){
    if(head==nullptr) return NULL;
    NODE *slow=head;
    NODE *fast=head;
    while(fast!=nullptr){
        slow=slow->next;
        fast=fast->next;
        if(fast!=nullptr){
            fast=fast->next;
        }
        if(fast==slow){
            // cout<<"Present at "<<slow->data<<endl;
            return slow;
    }
    }
    return NULL;
}
NODE *getStartingOfCycle(NODE *head){
    if(head==nullptr) return NULL;
    NODE *intersection=floyds_cycle(head);
    NODE *slow=head;
    while(slow != intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeLoop(NODE *head){
    if(head==nullptr) return;
    NODE *starting=getStartingOfCycle(head);
    NODE *temp = starting;
    while(temp->next!=starting){
        temp=temp->next;
    }
    temp->next=nullptr;
    cout<<"Loop removed\n";
}
int main(){
    NODE * node1=new NODE(30);
    NODE *tail=node1;
    NODE *head=node1;
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    InsertAtTail(tail,60);
    // print(head);
    tail->next=node1->next;
    if(DetectLoop(head)){
        cout<<"\nLoop detected.\n";
    }else{
        cout<<"No loop detected.\n";
    }
    NODE *starting=getStartingOfCycle(head);
    cout<<"Starting point of the loop is "<<starting->data<<endl;
    removeLoop(head);
    print(head);
    return 0 ;
}