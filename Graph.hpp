//dotandanino@gmail.com
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

namespace graph{
    //struct because we dont need methods and encapsulation
    struct Node
    {
        int id;
        double weight;
        Node* next;
        Node(int id,double weight):id(id),weight(weight),next(nullptr){};
    };
    class Graph{
        private:
            int numOfEdge;
            int numOfVertex;
            Node** adgencyList;
        public:
            Graph(int num_of_vertex);
            ~Graph();
            void addEdge(int src,int dest,int w=1);
            void removeEdge(int v1,int v2);
            void print_graph();
            int getNumOfVertex();
            int getNumOfEdge();
            Node** getAdgencyList();
            // void addOneWayEdge(int src,int dest,int w=1);
    };
}
#endif