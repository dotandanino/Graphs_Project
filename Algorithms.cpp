//dotandanino@gmail.com
#include "Algorithms.hpp"
using namespace graph;
Graph Algorithms::BFS(Graph& g,int src,int* d){
    const int size=g.getNumOfVertex();
    if(src<0 || src>=size){
        throw std::invalid_argument("there is no such vtx in the graph");
    }
    int* distance=new int[size];
    int* parent=new int[size];
    for(int i=0;i<size;i++){
        distance[i]=INT_MAX;
        parent[i]=INT_MAX;
    }
    distance[src]=0;
    Queue q=Queue();
    q.enqueue(src);
    Node** adjencyList=g.getAdgencyList();
    while (!q.isEmpty())
    {
        int v=q.dequeue();
        int d=distance[v];
        Node* neighbor=adjencyList[v];
        while(neighbor!=nullptr){
            int u=neighbor->id;
            if(distance[u]==INT_MAX){
                distance[u]=d+1;
                parent[u]=v;
                q.enqueue(u);
            }
            neighbor=neighbor->next;
        }
    }
    Graph gr=Graph(size);
    for(int i=0;i<size;i++){
        if(d!=nullptr){
            d[i]=distance[i];
        }
        if(i!=src && parent[i]<INT_MAX){
            gr.addOneWayEdge(parent[i],i);
        }
    }
    delete[] parent;
    delete[] distance;
    return gr;
}

Graph Algorithms::DFS(Graph& g,int src,int *discovery,int * finish){
    int size=g.getNumOfVertex();
    if(src<0 || src>=size){
        throw std::invalid_argument("there is no such vtx in the graph");
    }
    int* d=new int[size];
    int* f=new int[size];
    int* p=new int[size];
    int* color=new int[size];
    for(int i=0;i<size;i++){
        d[i]=INT_MAX;
        f[i]=INT_MAX;
        p[i]=INT_MAX;
        color[i]=0;
    }
    int time=0;
    dfsVisit(g,src,&time,color,d,f,p);
    for(int i=0;i<size;i++){
        if(color[i]==0){
            dfsVisit(g,i,&time,color,d,f,p);
        }
    }
    Graph gr=Graph(size);
    for(int i=0;i<size;i++){
        if(discovery!=nullptr){
            std::cout<<d[i]<<std::endl;
            discovery[i]=d[i];
        }
        if(finish!=nullptr){
            finish[i]=f[i];
        }
        if(i!=src && p[i]<INT_MAX){
            gr.addEdge(p[i],i);
        }
    }
    delete[] d;
    delete[] f;
    delete[] p;
    delete[] color;
    return gr;
}

void Algorithms::dfsVisit(Graph& g,const int v,int *time,int* colors,int* d,int* f,int* p){
    Node* adgents=g.getAdgencyList()[v];
    colors[v]=1;
    *time=*time+1;
    d[v]=*time;
    while (adgents!=nullptr)
    {
        if(colors[adgents->id]==0){
            p[adgents->id]=v;
            dfsVisit(g,adgents->id,time,colors,d,f,p);
        }
        adgents=adgents->next;
    }
    colors[v]=2;
    *time=*time+1;
    f[v]=*time;
}

Graph Algorithms::dijkstra(Graph& g,int src){
    int size=g.getNumOfVertex();
    if(src<0 || src>=size){
        throw std::invalid_argument("there is no such vtx in the graph");
    }
    Node** allEdge=g.getAdgencyList();
    for(int i=0;i<size;i++){
        Node* temp=allEdge[i];
        while(temp!=nullptr){
            if(temp->weight<0){
                throw std::invalid_argument("the weight of every edge must not be negative number");
            }
            temp=temp->next;
        }
    }
    Graph dijGraph(size);
    MinHeap minHeap(size);
    int* parent=new int[size];
    int* distance=new int[size];
    for (int i = 0; i < size; i++)
    {
        distance[i]=INT_MAX;
        parent[i]=INT_MAX;
    }
    distance[src]=0;
    minHeap.updatePriority(src,0);
    while(!minHeap.isEmpty()){
        int u=minHeap.extractMin();
        if(u!=src)//parent will always be in the range because we init parent before we insert him to the queue
            dijGraph.addEdge(parent[u],u,distance[u]-distance[parent[u]]);
        Node* adjencyList=g.getAdgencyList()[u];
        while (adjencyList!=nullptr)
        {
            relax(u,adjencyList->id,adjencyList->weight,distance,parent,minHeap);
            adjencyList=adjencyList->next;
        }
    }
    delete[] parent;
    delete[] distance;
    return dijGraph;
}
void Algorithms::relax(int u,int v,int w,int* d,int* p,MinHeap& minheap){
    if(d[v]>d[u]+w){
        minheap.updatePriority(v,d[u]+w);
        p[v]=u;
        d[v]=d[u]+w;
    }
}
Graph Algorithms::kruskal(Graph& g){
    int n=g.getNumOfVertex();
    int* connection=new int[n];
    Graph BFSG=BFS(g,0,connection);
    bool err=false;
    for(int i=0;i<n;i++){
        if(connection[i]==INT_MAX){
            err=true;
            break;
        }
    }
    delete[] connection;
    if(err){
        throw std::invalid_argument("The Graph must be connected");
    }
    int amountOfEdge=(int)(g.getNumOfEdge()/2);
    Node** adjencyList=g.getAdgencyList();
    Node** sortEdge=new Node*[amountOfEdge];
    Graph kruskalGraph(n);
    int k=0;//the index we want to initialize in the new array;
    for(int i=0;i<n;i++){
        Node* temp=adjencyList[i];
        while (temp!=nullptr && k<amountOfEdge)
        {
            if(i<temp->id){
                // after this when I will want to find the real vertex they will be i/n , i%n;
                sortEdge[k++]=new Node(i*n+temp->id,temp->weight);
            }
            temp=temp->next;
        }
    }
    for(int i=0;i<amountOfEdge;i++){
        for(int j=0;j<amountOfEdge-i-1;j++){
            if(sortEdge[j]->weight>sortEdge[j+1]->weight){
                Node* temp=sortEdge[j+1];
                sortEdge[j+1]=sortEdge[j];
                sortEdge[j]=temp;
            }
        }
    }
    UnionFind unionFind=UnionFind(n);
    for(int i=0;i<amountOfEdge;i++){
        int u=sortEdge[i]->id/n;
        int v=sortEdge[i]->id%n;
        if(unionFind.find(u)!=unionFind.find(v)){
            unionFind.myUnion(u,v);
            kruskalGraph.addEdge(u,v,sortEdge[i]->weight);
        }
        delete sortEdge[i];
    }
    
    delete[] sortEdge;
    return kruskalGraph;
}
Graph Algorithms::prim(Graph& g){
    int n=g.getNumOfVertex();
    int* connection=new int[n];
    Graph BFSG=BFS(g,0,connection);
    bool err=false;
    for(int i=0;i<n;i++){
        if(connection[i]==INT_MAX){
            err=true;
            break;
        }
    }
    delete[] connection;
    if(err){
        throw std::invalid_argument("The Graph must be connected");
    }
    int* weight= new int[n];
    int* nearNeighbor = new int[n];
    for(int i=0;i<n;i++){
        weight[i]=INT_MAX;
        nearNeighbor[i]=INT_MAX;
    }
    int s = rand() % n;// random number between 0 and n-1;
    Node* temp=g.getAdgencyList()[s];
    while (temp!=nullptr)
    {
        int k=temp->id;
        weight[k]=temp->weight;
        nearNeighbor[k]=s;
        temp=temp->next;   
    }
    Graph primGraph(n);
    UnionFind unionFind(n);
    int chosenEdge=0;
    while(chosenEdge<n-1){
        int minIndex=0;
        for(int i=1;i<n;i++){
            if(weight[i]<weight[minIndex]){
                minIndex=i;
            }
        }
        primGraph.addEdge(nearNeighbor[minIndex],minIndex,weight[minIndex]);
        chosenEdge++;
        unionFind.myUnion(s,minIndex);
        weight[minIndex]=INT_MAX;
        temp=g.getAdgencyList()[minIndex];
        while(temp!=nullptr){
            int x=temp->id;
            if(unionFind.find(x)!=unionFind.find(s)){
                if(weight[x]>temp->weight){
                    weight[x]=temp->weight;
                    nearNeighbor[x]=minIndex;
                }
            }
            temp=temp->next;
        }
    }
    delete[] weight;
    delete[] nearNeighbor;
    return primGraph;
}
