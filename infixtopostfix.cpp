#include <iostream>
#include "stack.h"
using namespace std;
class InfixToPostfix{
    string infix;
    
    public:
    InfixToPostfix(){
        cout<<"Enter infix expression"<<endl;
        cin>>infix;
    }
    int precedence(char c){
        if(c=='^')
            return 3;
        else if(c=='*'||c=='/')
            return 2;
        else if(c=='+'||c=='-')
            return 1;
        else
            return -1;
    }
    string postfix(){
        Stack s;
        string postfix="";
        char p,t;
        for(int i=0;i<infix.length();i++){
            if(infix[i]=='('){
                s.push(infix[i]);
            }else if(infix[i]==')'){
                p=s.pop();
                while(p!='('){
                    postfix=postfix+p;
                    p=s.pop();
                }
                s.push(infix[i]);
            }else if(precedence(infix[i])!=-1){
                t=s.top();
                while(!s.isEmpty() && precedence(infix[i])<=precedence(t)){
                    p=s.pop();
                    postfix=postfix+p;
                    t=s.top();
                }
                s.push(infix[i]);
            }else{
                postfix=postfix+infix[i];
            }
        }
        while(!s.isEmpty()){
            p=s.pop();
            postfix=postfix+p;
        }
        return postfix;
    }
};
int main(){
    InfixToPostfix i;
    cout<<"Postfix:"<<i.postfix()<<endl;
    return 0;
}