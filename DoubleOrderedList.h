#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
    node(int data):data(data),next(NULL),prev(NULL){}
};
class DoubleOrderedList{
    node* head;
    node* tail;
    public:
    DoubleOrderedList():head(NULL),tail(NULL){}
    void insert(int data){
        node* temp=new node(data);
        node* curr =head;
        node* prev=NULL;
        while(curr!=NULL && curr->data<data){
            prev=curr;
            curr=curr->next;
        }
        if(prev==NULL){
            temp->prev=NULL;
            head=temp;
        }else{
            temp->prev=prev;
            prev->next=temp;
        }
        if(curr==NULL){
            temp->next=NULL;
            tail=temp;
        }else{
            temp->next=curr;
            curr->prev=temp;
        }
    }
    void remove(int data){
        node* curr=head;
        while(curr!=NULL && curr->data<data){
            curr=curr->next;
        }
        if(curr==NULL){
            cout<<"Data not found"<<endl;
            return ;
        }
        if(curr->data==data){
            if(curr->prev){
                curr->prev->next=curr->next;
            }else{
                head=head->next;
            }
            if(curr->next){
                curr->next->prev=curr->prev;
            }else{
                tail=tail->prev;
            }
            delete curr;
        }
    }
    void display(bool n){
        if(n==true){
            node* temp=head;
            cout<<"[";
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<"]"<<endl;
        }else{
            node* temp=tail;
            cout<<"[";
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->prev;
            }
            cout<<"]"<<endl;
        }
    }
};