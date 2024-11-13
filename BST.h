#include <iostream>
using namespace std;
struct node{
    int data;
    node* right;
    node* left;
    node(int data) : data(data), right(NULL),left(NULL){}
};
class BST{
    node* root;
    BST():root(NULL){}
    void insert(node* &root,int data){
        if(root==NULL){
            root=new node(data);
            return;
        }
        if(root->data>data){
            insert(root->left,data);
        }else{
            insert(root->right,data);
        }
    }
    void inorder(node* root){
        if (root==NULL)return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void preorder(node* root){
        if(root==NULL)return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(node* root){
        if(root==NULL)return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    node* maxnode(node* root){
        if(root->right==NULL){
            return root;
        }
        return maxnode(root->right);
    }
    node* minnode(node* root){
        if(root->left==NULL){
            return root;
        }
        return minnode(root->left);
    }
    void remove(node* &root,int data){
        if(root==NULL){
            return;
        }
        if(root->data<data){
            remove(root->right,data);
        }else if(root->data>data){
            remove(root->left,data);
        }else{
            if(root->right==NULL){
                node* dlt=root;
                root=root->left;
            }else if (root->left==NULL){
                node* dlt=root;
                root=root->right;
            }else{
                node* dlt=root;
                node* largest=maxnode(root->left);
                root->data=largest->data;
                remove(dlt->left,largest->data);
            }
        }
    }
};



