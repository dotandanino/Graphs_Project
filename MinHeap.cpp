//dotandanino@gmail.com
#include "MinHeap.hpp"
using namespace graph;
/*
in my implement of the MinHeap i used array with size that i got in the constructor
every time i check what is the minimal item in the array and return his index.
*/
// in the constructor I build the array and put 2^31 in every cell
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
//return the index of the min item and put 2^31 instead
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
//update the priority of vertex
void MinHeap::updatePriority(int vertex,int priority){
    if(vertex>=size || vertex<0){
        throw std::invalid_argument("there is no such vtx in the graph");
    }
    this->arr[vertex]=priority;
}
MinHeap::~MinHeap(){
    delete[] arr;
}
//אני הגדרתי ערימה ריקה בתור ערימה שאין בה אף תא שהוא קטן מ 2 בחזקת 31
bool MinHeap::isEmpty() const{
    for(int i=0;i<size;i++){
        if(this->arr[i]<INT_MAX){
            return false;
        }
    }
    return true;
}
