#include <iostream>
#include "OrderedList.h"
using namespace std;
class HashSet{
    OrderedList *L;
    int size;
    public:
    HashSet(){
        cout<<"Enter the target size: ";
        cin>>size;
        size*=1.25;
        L=new OrderedList[size];
    }
    inline int Hash(int key){
        return key%size;
    }
    void insert(int key){
        (L+Hash(key))->insert(key);
    }
    inline void remove(int key){
        (L+Hash(key))->remove(key);
    }
    inline int  search(int key){
        return (L+Hash(key))->search(key);
    }
    void display(){
        for(int i=0;i<size;i++){
            (L+i)->display();
        }
    }
};
