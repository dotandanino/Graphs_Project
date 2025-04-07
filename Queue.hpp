//dotandanino@gmail.com
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Graph.hpp"
namespace graph{
    class Queue
    {
    private:
        Node* front;
        Node* rear;
    public:
        Queue();
        ~Queue();
        void enqueue(int vtxNUM);
        int dequeue();
        int peek() const;
        bool isEmpty() const;
    };
}
#endif