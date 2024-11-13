#include <iostream>
using namespace std;
struct Dnode{
    int data;
    int rank;
    Dnode* parent;
     Dnode(): data(0),rank(0),parent(NULL){}
    Dnode(int data): data(data),rank(0),parent(NULL){}
};
class DisjointSet{
    Dnode** head;
    public:
    int n;
    DisjointSet(){
        cout<<"Enter the number of elements: ";
        cin>>n;
        head=new Dnode*[n];
    }
    void makeSet(int x){
        head[x]=new Dnode(x);
        head[x]->rank=0;
        head[x]->parent=head[x];
    }
    Dnode* findSet(int x){
        Dnode* temp=head[x];
        if(temp->parent==temp){
            return temp;
        }
        return findSet(temp->parent->data);
    }
    void unionSet(int x,int y){
        Dnode* xSet=findSet(x);
        Dnode* ySet=findSet(y);
        if(xSet->rank<ySet->rank){
            xSet->parent=ySet;
        }else if(xSet->rank>ySet->rank){
            ySet->parent=xSet;
        }else{
            xSet->parent=ySet;
            xSet->rank++;
        }
    }
};
int main(){
    DisjointSet d;
    for (int i = 0; i < d.n; i++) {
        d.makeSet(i);
    }
    int ch,x,y;
    while (ch != 4) {
        cout << "Enter 1 for Union, 2 for Find, 3 for Display, 4 to exit" << endl;
        cin >> ch;
        switch (ch) {
            case 1:{
                cout << "Enter two numbers to union: ";
                cin >> x >> y;
                d.unionSet(x, y);
                break;
            } 
            case 2:{
                cout << "Enter a number to find: ";
                cin >> x;
                Dnode* temp = d.findSet(x);
                cout << "Parent of " << x << " is " << temp->data << endl;
                break;
            }
                
            case 3:{
                cout << "Displaying the tree" << endl;
                for (int i = 0; i < d.n; i++) {
                    Dnode* temp = d.findSet(i);
                    cout << i << " -> " << temp->data << endl;
                }
                break;
            }     
            default:
                break;
            }
    }
    return 0;
}