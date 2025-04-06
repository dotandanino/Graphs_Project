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
        void relax(int u,int v,int w,int* d,int* p,MinHeap& minheap);
        void dfsVisit(Graph& g,const int v,int *time,int* colors,int* d,int* f,int* p);
        public:
            Graph BFS(Graph& g, int src,int* d=nullptr);
            Graph DFS(Graph& g, int src,int* discovery=nullptr,int * finish=nullptr);
            Graph dijkstra(Graph& g,int src);
            Graph prim(Graph& g);
            Graph kruskal(Graph& g);
    };
}
#endif