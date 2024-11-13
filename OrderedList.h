#include <iostream>
#include "Node.h"
using namespace std;
class OrderedList{
    node* head;
    public:
    OrderedList():head(NULL){}
    void insert(int data){
        node* temp=new node(data);
        node* curr=head;
        node* prev=NULL;
        while(curr!=NULL && curr->data<data){
            prev=curr;
            curr=curr->next;
        }
        if(prev==NULL){
            temp->next=head;
            head=temp;
        }else{
            temp->next=prev->next;
            prev->next=temp;
        }
    }
    int search(int data){
        node* curr=head;
        while(curr!=NULL){
            if(curr->data==data){
                return data;
            }
            curr=curr->next;
        }
        return -1;
    }
    void remove(int data){
        node* curr=head;
        node* prev=NULL;
        while(curr!=NULL && curr->data!=data){
            prev=curr;
            curr=curr->next;
        }
        if(curr==NULL){
            cout<<"Data not found"<<endl;
            return ;
        }
        if(prev==NULL){
            if(curr->data==data){
                head=head->next;
                delete curr;
            }else{
                cout<<"Data not found"<<endl;
            }
        }else{
            if(curr->data==data){
                prev->next=curr->next;
                delete curr;
            }else{
                cout<<"Data not found"<<endl;
            }
        }
    }
    void display(){
        for(node* temp=head;temp!=NULL;temp=temp->next){
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
    node* gethead(){
        return head;
    }
};


