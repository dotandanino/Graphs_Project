//dotandanino@gmail.com

#include "Queue.hpp"
using namespace graph;
Queue::Queue(){
    this->front=nullptr;
    this->rear=nullptr;
}
void Queue::enqueue(int vtxNUM){
    Node* n=new Node(vtxNUM,0);
    if(front==nullptr){
        front=n;
        rear=n;
    }
    else{
        rear->next=n;
        rear=rear->next;
    }
}
bool Queue::isEmpty(){
    return (front==nullptr);
}
int Queue::dequeue(){
    if(front==nullptr)
        throw std::underflow_error("you cant pop from empty queue");
    int x=front->id;
    Node* temp=front;
    front=front->next;
    delete temp;
    return x;
}
int Queue::peek(){
    if(front==nullptr)
        throw std::underflow_error("you cant pop from empty queue");
    return(front->id);
}
Queue::~Queue(){
    Node* temp=front;
    while (front!=nullptr)
    {
        temp=front;
        front=front->next;
        delete temp;
    }
}