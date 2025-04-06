//dotandanino@gmail.com
#include "MinHeap.hpp"
using namespace graph;
MinHeap::MinHeap(int size){
    if(size<=0){
        throw std::underflow_error("size must be positive number");
    }
    this->arr=new int[size];
    this->size=size;
    for(int i=0;i<this->size;i++){
        this->arr[i]=INT_MAX;
    }
}
int MinHeap::extractMin(){
    if(this->isEmpty()){
        throw std::invalid_argument("the heap is empty");
    }
    int minInd=0;
    for(int i=0;i<this->size;i++){
        if(arr[minInd]>arr[i]){
            minInd=i;
        }
    }
    arr[minInd]=INT_MAX;
    return minInd;
}
void MinHeap::updatePriority(int vertex,int priority){
    if(vertex>=size || vertex<0){
        throw std::invalid_argument("there is no such vtx in the graph");
    }
    this->arr[vertex]=priority;
}
MinHeap::~MinHeap(){
    delete[] arr;
}
bool MinHeap::isEmpty(){
    for(int i=0;i<size;i++){
        if(this->arr[i]<INT_MAX){
            return false;
        }
    }
    return true;
}
