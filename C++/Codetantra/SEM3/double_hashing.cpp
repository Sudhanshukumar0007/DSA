#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define SIZE 13
#define PRIME 7
int HashTable[SIZE];
int hash1(int x){
    return x%SIZE;
}
int hash2(int x){
    return PRIME-(x%PRIME);
}
void insertEle(int x){
    int index,start;
    index = hash1(x);
    start = index;
    int i = 1;
    while(HashTable[index]!=-1){
        if(HashTable[index]==-1){
            break;
        }
        index = (index + i*hash2(x))%SIZE;
        if(index==start){
            cout<<"HashTable is full.\n";
            return;
        }
        i++; 
    } 
    HashTable[index]=x;
    cout<<"Successfully inserted.\n";
}
void deleteEle(int x){
    int index,start;
    index = hash1(x);
    start = index;
    int i=1;
    while(HashTable[index]!=x){
        if(HashTable[index]==x){
            break;
        }
        index = (index + i*hash2(x))%SIZE;
        if(index==start){
            cout<<"Element not found.\n";
            return;
        }
        i++;
    }
    HashTable[index]=-1;
    cout<<"Successfully deleted.\n";
}
void searchEle(int x){
    int index,start;
    index=hash1(x);
    start = index;
    int i = 1;
    while(HashTable[index]!=x){
        if(HashTable[index]==x){
            break;
        }
        index = (index + i*hash2(x))%SIZE;
        if(index==start){
            cout<<"Element not found.\n";
            return;
        }
        i++;
    }
    cout<<"Element found.\n";
}
void print(){
    int i;
    for(i=0;i<SIZE;i++){
        cout<<"["<<i<<"]"<<HashTable[i]<<endl;
    }
}
int main() {
	int x, op, i=0;
	for(i=0;i<SIZE;i++)
		HashTable[i]=-1;
	while(1) {
		cout << "1.Insert 2.Delete 3.Search 4.Print 5.Exit\n";
		cout << "Enter your option : ";
		cin >> op;
		switch(op) {
			case 1:	cout << "Enter an element to be inserted : ";
					cin >> x;
					insertEle(x);
					break;
			case 2:
					cout << "Enter an element to be deleted : ";
					cin >> x;
					deleteEle(x);
					break;
			case 3: 
					cout << "Enter an element to be searched : ";
					cin >> x;
					searchEle(x);
					break;
			case 4: 
					print();
					break;
			case 5:	exit(0);
		}
	}
}