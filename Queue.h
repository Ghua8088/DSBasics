#include <iostream>
#include "Node.h"
using namespace std;
class Queue{
    node* front;
    node* rear;
    public:
    Queue():front(NULL),rear(NULL){}
    void enqueue(int data){
        node* temp=new node(data);
        if(front==NULL){
            rear=temp;
            front=rear;
            return;
        } 
        rear->next=temp;
        rear=temp;
    }
    int dequeue(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(front==rear){
            int data=front->data;
            delete front;
            front=rear=NULL;
            return data;
        }
        int data=front->data;
        node* temp=front;
        front=front->next;
        delete temp;
        return data;
    }
    bool isEmpty(){
        return front==NULL;
    }
};

