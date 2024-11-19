#include <iostream>
using namespace std;
struct  node{
    int data;
    node* next;
    node* prev;
    node(int data1):data(data1),next(NULL),prev(NULL){}
};

class CDLL{
    node* head;
    node* rear;
    public:
    CDLL():head(NULL),rear(NULL){}
    void insert(int data){
        if(head==NULL){
            head=new node(data);
            rear=head;
        }else{
            node* temp=new node(data);
            rear->next=temp;
            temp->prev=rear;
            head->prev=temp;
            temp->next=head;
            rear=temp;

        }
    }
    void remove(int data){
        cout<<"Deleting "<<data<<" from list"<<endl;
        node* temp=head;
        if(isEmpty()){
            cout<<"List is empty"<<endl;
        }
        do{
            if(temp->data==data){
                break;
            }
            temp=temp->next;
        }while(temp!=head);
        
        if(temp->data==data){
            if(temp==head && temp==rear){
                head=NULL;
                rear=NULL;
            }else{
                 temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                if (temp == head) head = temp->next; 
                if (temp == rear) rear = temp->prev; 
            }
            delete temp;
        }else{
            cout<<"Element not found"<<endl;
        }
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }else{
            return false;
        }
    }
    void display(){
        node* temp=head;
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
    
    ~CDLL(){
        while (!isEmpty()) {
            remove(head->data);
        }
    }
};



