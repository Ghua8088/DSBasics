#include<iostream>
#include "Queue.h"
#include "OrderedList.h"
#include "Stack.h"
using namespace std;
struct GraphNode{
    int data;
    int d;
    int f;
    GraphNode* pi;
    OrderedList* adj;
    int status;
    GraphNode* next;
    GraphNode(int data):data(data),next(NULL),status(0),pi(NULL),f(0),d(0){
        adj=new OrderedList();
    }
    void display(){
        cout<<data<<","<<f<<","<<d<<",";
        if(pi!=NULL){
            cout<<pi->data;
        }else{
            cout<<"NULL";
        }
    }
};
class Graph{
    GraphNode* head;
    public:
    Graph():head(NULL){}
    void insert(int data){
        cout<<"Inserting"<<data<<endl;
        GraphNode* temp=new GraphNode(data);
        GraphNode* succ=head;
        GraphNode* pred=NULL;
        while(succ!=NULL && data>succ->data){
            pred=succ;
            succ=succ->next;
        }
        if(pred==NULL){
            temp->next=head;
            head=temp;
        }else{
            temp->next=pred->next;
            pred->next=temp;
        }
    }
    GraphNode* get(int data){
        GraphNode* temp=head;
        while(temp!=NULL){
            if(temp->data==data){
                return temp;
            }
            temp=temp->next;
        }
    }
    void connect(int p,int c){
        GraphNode* parent=get(p);
        if(parent==NULL){
            cout<<"could not find parent"<<endl;
            return;
        }
        parent->adj->insert(c);
        cout<<"Connecting nodes:"<<p<<","<<c<<endl;
    }
    void BFS(int s){
        GraphNode* r=head;
        while(r!=NULL){
            r->pi=NULL;
            r->d=0;
            r->f=0;
            r->status=0;
            r=r->next;
        }
        r=get(s);
        r->status=1;
        Queue q;
        q.enqueue(r->data);
        cout<<"BFS:";
        while(!q.isEmpty()){
            GraphNode* u=get(q.dequeue());
            cout<<u->data<<" -> ";
            for(node* vl=u->adj->gethead();vl!=NULL;vl=vl->next){
                GraphNode* v=get(vl->data);
                if(v->status==0){
                    q.enqueue(v->data);
                    v->status=1;
                    v->pi=u;
                    v->d=u->d+1;
                }
            }
            u->status=2;
        }  
        cout<<endl;
    }
    void DFS(){
        GraphNode* r=head;
        while(r!=NULL){
            r->pi=NULL;
            r->d=0;
            r->f=0;
            r->status=0;
            r=r->next;
        }
        r=head;
        int d=0;
        Stack s;
        r->status=1;
        s.push(r->data);
        cout<<"DFS:";
        while(!s.isEmpty()){
            
            GraphNode* u=get(s.pop());
            cout<<u->data<<" -> ";
            for(node* vl=u->adj->gethead();vl!=NULL;vl=vl->next){
                GraphNode* v=get(vl->data);
                if(v->status==0){
                    v->status=1;
                    v->pi=u;
                    v->d=++d;
                    s.push(v->data);
                }
            }
            u->status=2;
            u->f=++d;
        }
    }
    void display(){
        cout<<endl;
        cout<<"Starting display"<<endl;
        GraphNode* temp=head;
        while(temp!=NULL){
            cout<<"{";
            temp->display();
            cout<<"}"<<"->";
            temp->adj->display();
            temp=temp->next;
        }
    }
};
int main(){
    Graph g;
    g.insert(1);
    g.insert(2);
    g.insert(3);
    g.insert(4);
    g.insert(5);
    g.insert(6);
    g.connect(1, 2);
    g.connect(1, 3);
    g.connect(2, 4);
    g.connect(2, 5);
    g.connect(4, 3);
    g.connect(5, 6);
    g.connect(6, 3);
    cout<<"Starting BFS"<<endl;
    g.BFS(1);
    g.display();
    g.DFS();
    g.display();
    return 0;   
}