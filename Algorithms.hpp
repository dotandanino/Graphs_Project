//dotandanino@gmail.com
#ifndef ALGOHRITHMS_H
#define ALGOHRITHMS_H
#include "Graph.hpp"
#include "Queue.hpp"
#include "MinHeap.hpp"
#include "UnionFind.hpp"
#include <limits.h>
namespace graph{
    class Algorithms{
        void relax(int u,int v,int w,int* d,int* p,MinHeap& minheap) const;
        void dfsVisit(Graph& g,const int v,int *time,int* colors,int* d,int* f,int* p) const;
        public:
            Graph BFS(Graph& g, int src,int* d=nullptr) const;
            Graph DFS(Graph& g, int src,int* discovery=nullptr,int * finish=nullptr) const;
            Graph dijkstra(Graph& g,int src,int * d=nullptr) const;
            Graph prim(Graph& g) const;
            Graph kruskal(Graph& g) const;
    };
}
#endif