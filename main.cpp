//dotandanino@gmail.com
#include "main.hpp"
using namespace graph;
int main() {
    //////////////////
    ////// Queue /////
    //////////////////
    std::cout<<std::endl<<"Queue"<<std::endl;

    Queue q=Queue();
    q.enqueue(12);
    q.enqueue(8);
    q.enqueue(2005);
    int x=q.dequeue();
    int y=q.peek();
    int y2=q.dequeue();
    std::cout<<"x is: "<<x<<" y is: "<<y<<"y2 is: "<<y2<<std::endl;

    //////////////////
    ////// Graph /////
    //////////////////
    std::cout<<std::endl<<"Graph"<<std::endl;

    Graph gr(10) ;
        
    gr.addEdge(0, 1, 10);
    gr.addEdge(0, 4, 20);
    gr.addEdge(1, 2, 30);
    gr.addEdge(1, 3, 40);
    gr.addEdge(2, 3, 60);
    gr.addEdge(3, 4, 70);
    gr.addEdge(1, 4, 50);
    gr.addEdge(2, 5, 40);
    gr.addEdge(3, 6, 30);
    gr.addEdge(2, 6, 7);
    gr.addEdge(5, 7, 20);
    gr.addEdge(5, 8, 40);
    gr.addEdge(0, 8, 50);
    gr.addEdge(7, 9, 50);
    gr.addEdge(3, 9, 10);
    gr.print_graph();

    //////////////////
    /// union find ///
    //////////////////
    std::cout<<std::endl<<"UNION FIND:"<<std::endl;
    UnionFind uf(10);
    uf.myUnion(2,3);
    uf.myUnion(2,4);
    int f2=uf.find(2);
    int f3=uf.find(3);
    int f4=uf.find(4);
    int f5=uf.find(5);
    std::cout<<"f2: "<<f2<<" f3: "<<f3<<" f4:"<<f4<<" f5: "<<f5<<std::endl;


    //////////////////
    //// Min Heap ////
    //////////////////

    std::cout<<std::endl<<"Min Heap:"<<std::endl;

    MinHeap heap(5);
    heap.updatePriority(0,12);
    heap.updatePriority(1,8);
    heap.updatePriority(2,2005);
    heap.updatePriority(3,28);
    heap.updatePriority(4,17);
    int min0=heap.extractMin();
    int min1=heap.extractMin();
    int min2=heap.extractMin();
    int min3=heap.extractMin();
    int min4=heap.extractMin();
    std::cout<<"the order is: " << min0 <<" "<<min1<<" " <<min2<<" " <<min3<<" " <<min4<<std::endl;




    //////////////////
    /////// MST //////
    //////////////////

    std::cout<<"MST Algorithms"<<std::endl;
    Algorithms a;
    Graph g(9);
    //A graph from the lesson to check its good
    g.addEdge(0, 1, 9);  // a - b
    g.addEdge(0, 3, 1);  // a - d
    g.addEdge(1, 2, 3);  // b - c
    g.addEdge(1, 4, 4);  // b - e
    g.addEdge(1, 5, 3);  // b - f
    g.addEdge(2, 3, 5);  // c - d
    g.addEdge(2, 5, 12);  // c - f
    g.addEdge(2, 4, 1); // c - e
    g.addEdge(3, 6, 8);  // d - g
    g.addEdge(4, 8, 6);  // e - i
    g.addEdge(5, 7, 2);  // f - h
    g.addEdge(5, 6, 5); // f - g
    g.addEdge(6, 7, 2);  // g - h
    g.addEdge(7, 8, 1);  // h - i
    g.addEdge(7, 5, 2);  // h - f
    Graph kruskalGraph=a.kruskal(g);
    Graph primGraph=a.prim(g);
    std::cout<<std::endl<<"KRUSKAL:"<<std::endl<<std::endl;
    kruskalGraph.print_graph();
    std::cout<<std::endl<<"PRIM:"<<std::endl<<std::endl;
    primGraph.print_graph();

    //////////////////
    //// dijkstra ////
    //////////////////

    //A graph from the lesson to check its good

    std::cout<<std::endl<<"dijkstra"<<std::endl;
    Graph d(4);
    d.addEdge(0,1,10);
    d.addEdge(0,2,5);
    d.addEdge(1,2,4);
    d.addEdge(2,3,1);
    d.addEdge(1,3,2);
    Graph after=a.dijkstra(d,0);
    after.print_graph();

    //////////////////
    /////// BFS //////
    //////////////////

    std::cout<<std::endl<<"BFS"<<std::endl;

    Graph bfs_try(9);
    bfs_try.addEdge(0,1);
    bfs_try.addEdge(0,5);
    bfs_try.addEdge(2,1);
    bfs_try.addEdge(7,1);
    bfs_try.addEdge(0,7);
    bfs_try.addEdge(2,1);
    bfs_try.addEdge(2,6);
    bfs_try.addEdge(5,4);
    bfs_try.addEdge(5,8);
    bfs_try.addEdge(6,7);
    bfs_try.addEdge(6,8);
    bfs_try.addEdge(7,8);
    Graph b=a.BFS(bfs_try,0);
    b.print_graph();

    //////////////////
    /////// DFS //////
    //////////////////

    std::cout<<std::endl<<"DFS"<<std::endl<<std::endl;
    Graph dfs_try(9);
    dfs_try.addEdge(0,1);
    dfs_try.addEdge(0,5);
    dfs_try.addEdge(2,1);
    dfs_try.addEdge(7,1);
    dfs_try.addEdge(0,7);
    dfs_try.addEdge(2,6);
    dfs_try.addEdge(5,4);
    dfs_try.addEdge(5,8);
    dfs_try.addEdge(6,7);
    dfs_try.addEdge(6,8);
    dfs_try.addEdge(7,8);
    dfs_try.addEdge(3,4);
    dfs_try.addEdge(3,2);
    dfs_try.addEdge(3,6);
    Graph d2=a.DFS(dfs_try,0);
    d2.print_graph();
    return 0;
}