#include <iostream>
using namespace std;
#include "Node.h"
class Stack{
    node* head;
    public:
    Stack():head(NULL){}
    void push(int data){
        node* tmp=new node(data);
        tmp->next=head;
        head=tmp;
    }
    int pop(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int data=head->data;
        node* tmp=head;
        head=head->next;
        delete tmp;
        return data;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
    int top(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }
    ~Stack(){
        while (head != NULL) {
            pop();
        }
    }
};
