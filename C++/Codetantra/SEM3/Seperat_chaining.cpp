#include<bits/stdc++.h>
using namespace std;
#define SIZE 10
class node{
    public:
    int data;
    node *next;
};
class HashTable{
    public:
    node *table[SIZE];
    node *newNode(int x);
    int hash(int x);
    void insertEle(int x);
    void deleteEle(int x);
    void searchEle(int x);
    void display();
};
int HashTable::hash(int x){
    return x % SIZE;
}
node * HashTable::newNode(int x){
    node *temp = new node;
    temp->data=x;
    temp->next=nullptr;
    return temp;
}
void HashTable::insertEle(int x){
    int index = hash(x);
    node *temp;
    temp=newNode(x);
    temp->next=table[index];
    table[index]=temp;
}
void HashTable::deleteEle(int x){
    int index = hash(x);
    node * temp = table[index];
    node *prev = NULL;
    if(temp==nullptr){
        cout<<"Element not found.\n";
        return;
    }else if(temp->data==x){
        table[index] = temp->next;
        delete temp;
        cout<<"Successfully deleted.\n";
        return ;
    }else{
        while(temp!=nullptr && temp->data!=x){
            prev = temp;
            temp = temp->next;
        }if(temp==NULL){
            cout<<"Element not found.\n";
            return;
        }else{
            prev->next=temp->next;
            delete temp;
            cout<<"Successfully deleted.\n";
            return;
        }
    }
}
void HashTable::searchEle(int x){
    int index = hash(x);
    node *temp;
    temp = table[index];
    while(temp!=nullptr && temp->data!=x){
        temp=temp->next;
    }if(temp==nullptr){
        cout<<"Element not found.\n";
    }else{
        cout<<"Element found.\n";
    }
}
void HashTable::display(){
    int i;
    for(int i=0;i<SIZE;i++){
        node*temp=table[i];
        cout<<"["<<i<<"]"<<"-> ";
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
    }
}
HashTable ht;
int main() {
	int x, op, i=0;
	for(i=0;i<SIZE;i++)
		ht.table[i]=NULL;
	while(1) {
		cout << "1.Insert 2.Delete 3.Search 4.Print 5.Exit\n";
		cout << "Enter your option : ";
		cin >> op;
		switch(op) {
			case 1:	cout << "Enter an element to be inserted : ";
					cin >> x;
					ht.insertEle(x);
					break;
			case 2:
					cout << "Enter an element to be deleted : ";
					cin >> x;
					ht.deleteEle(x);
					break;
			case 3: 
					cout << "Enter an element to be searched : ";
					cin >> x;
					ht.searchEle(x);
					break;
			case 4: 
					ht.display();
					break;
			case 5:	exit(0);
		}
	}
}