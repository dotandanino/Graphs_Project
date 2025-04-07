//dotandanino@gmail.com
#ifndef minHeap_H
#define minHeap_H
#include "Graph.hpp"
#include <limits.h>
namespace graph{
    class MinHeap
    {
    private:
        int size;
        int* arr;
    public:
        MinHeap(int size);
        ~MinHeap();
        int extractMin();//return the index of the minimal item
        bool isEmpty() const;
        void updatePriority(int vertex,int priority);
    };
}
#endif