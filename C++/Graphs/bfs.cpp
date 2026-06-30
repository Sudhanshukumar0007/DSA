#include<bits/stdc++.h>
using namespace std;
#define MAX 99
class GNODE{
    public:
    GNODE *next;
    int vertex;
};
class Graph{
    public:
    GNODE *graph[20];
    int visited[20];
    int N,E;
    void BFS(int start_vertex);
};
class Queue{
    public:
    int queue[MAX],front,rear;
    Queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int vertex);
    int isEmpty();
    int dequeue();
};

void Queue::enqueue(int vertex){
    if(rear==MAX-1){
        cout<<"Queue overflow.\n";
    }else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=vertex;
    }
}
int Queue::dequeue(){
    int delitm;
    if(front==-1 || front>rear){
        cout<<"Queue underflow.\n";
        exit(0);
    }
    delitm = queue[front];
    front++;
    return delitm;
}
int Queue::isEmpty(){
    if(front==-1 || front>rear){
        return 1;
    }else{
        return 0;
    }
}
void Graph::BFS(int start_vertex){
    Queue q;
    visited[start_vertex]=1;
    q.enqueue(start_vertex);
    while(!q.isEmpty()){
        int v = q.dequeue();
        cout<<v<<endl;
        GNODE *g = graph[v];
        while(g!=nullptr){
            int adj = g->vertex;
            if(visited[adj]==0){
                visited[adj] = 1;
                q.enqueue(adj);
            }
            g=g->next;
        }
    }
}
int main(){
    int s,d,i,j,v;
    Graph g;
    GNODE *p,*q;
    cout<<"Enter the number of vertices : ";
    cin>>g.N;
    cout<<"Enter the number of edges : ";
    cin>>g.E;
    for(int i=1;i<=g.N;i++){
        g.visited[i]=0;
        g.graph[i] = nullptr;
    }
    for(int i=1;i<=g.E;i++){
        cout<<"Enter Source : ";
        cin >> s;
        cout<<"Enter Destination : ";
        cin >> d;
        q = new GNODE;
        q->vertex=d;
        q->next = nullptr;
        if(g.graph[s]==nullptr){
            g.graph[s]=q;
        }else{
            p = g.graph[s];
            while(p->next!=nullptr)
                p=p->next;
            p->next=q;
        } 
    }

    cout<<"Enter Start vertex for BFS : ";
    cin>>v;
    cout<<"BFS of graph : \n";
    g.BFS(v);
    cout<<"\n";
    return 0;
}