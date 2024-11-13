#include <iostream>
using namespace std;
void selectionsort(int* arr,int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[min],arr[i]);
        }
    }
}
void insertionsort(int* arr,int n){
    int j;
    for(int i=0;i<n;i++){
        j=i;
        while(j>0 && arr[j]<arr[j-1]){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}