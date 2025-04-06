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
        int extractMin();
        bool isEmpty();
        void updatePriority(int vertex,int priority);
    };
}
#endif