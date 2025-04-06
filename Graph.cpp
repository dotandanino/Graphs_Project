//dotandanino@gmail.com
#include "Graph.hpp"
using namespace graph;
Graph::Graph(int num_of_vertex)
{
    if(num_of_vertex<=0){
        throw std::invalid_argument("num of vertex must be positive number");
    }
    this->numOfVertex=num_of_vertex;
    this->numOfEdge=0;
    this->adgencyList=new Node*[num_of_vertex];
    for(int i=0;i<num_of_vertex;i++){
        this->adgencyList[i]=nullptr;
    }
}
int Graph::getNumOfVertex(){
    return numOfVertex;
}
Node** Graph::getAdgencyList(){
    return adgencyList;
}
int Graph::getNumOfEdge(){
    return numOfEdge;
}
Graph::~Graph()
{
    for (int i = 0; i < numOfVertex; i++) {
        Node* current = adgencyList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adgencyList;
}
void Graph::addEdge(int src,int dest,int w){
    if(src>=numOfVertex || dest >=numOfVertex || src<0 || dest<0){
        throw std::out_of_range("the graph doesn't contain this vertex");
    }
    Node* temp=adgencyList[src];
    bool flag=false;
    while(temp!=nullptr){
        if(temp->id==dest){
            flag=true;
            temp->weight=w;
            break;
        }
        temp=temp->next;
    }
    if(!flag){
        Node *n1 =new Node(dest,w);
        n1 -> next=adgencyList[src];
        adgencyList[src]=n1;
        numOfEdge++;
    }
    temp=adgencyList[dest];
    flag=false;
    while(temp!=nullptr){
        if(temp->id==src){
            flag=true;
            temp->weight=w;
            break;
        }
        temp=temp->next;
    }
    if(!flag){
        Node* n2=new Node(src,w);
        n2 ->next = adgencyList[dest];
        adgencyList[dest]=n2;
        numOfEdge++;
    }
}

void Graph::addOneWayEdge(int src,int dest,int w){
    if(src>=numOfVertex || dest >=numOfVertex || src<0 || dest<0){
        throw std::out_of_range("the graph doesn't contain this vertex");
    }
    Node* temp=adgencyList[src];
    bool flag=false;
    while(temp!=nullptr){
        if(temp->id==dest){
            flag=true;
            temp->weight=w;
            break;
        }
        temp=temp->next;
    }
    if(!flag){
        Node *n1 =new Node(dest,w);
        n1 -> next=adgencyList[src];
        adgencyList[src]=n1;
        numOfEdge++;
    }
}

void Graph::removeEdge(int v1,int v2){
    int find=0;
    if(v1>=numOfVertex || v2 >=numOfVertex || v1<0 || v2<0){
        throw std::out_of_range("the graph doesn't contain this vertex");
    }
    Node* n=adgencyList[v1];
    Node* prev=nullptr;
    while (n!=nullptr)
    {
        if(n->id==v2){
            find=1;
            if(prev!=nullptr){
                prev->next=n->next;
            }
            else{
                adgencyList[v1]=n->next;
            }
            numOfEdge--;
            delete n;
            break;
        }
        prev=n;
        n=n->next;
    }
    if(find==0){
        throw std::invalid_argument("the graph doesn't contain this edge");
    }
    find=0;
    n=adgencyList[v2];
    prev=nullptr;
    while (n!=nullptr)
    {
        if(n->id==v1){
            find=1;
            if(prev!=nullptr){
                prev->next=n->next;
            }
            else{
                adgencyList[v2]=n->next;
            }
            delete n;
            numOfEdge--;
            break;
        }
        prev=n;
        n=n->next;
    }
    if(find==0){
        throw std::invalid_argument("the graph doesn't contain this edge");
    }
}
void Graph::print_graph(){
    if(adgencyList!=nullptr){
        for(int i=0;i<numOfVertex;i++){
            std::cout<<"the edges of vertex number "<<i<<" are:"<<std::endl;
            if(adgencyList[i]==nullptr){
                std::cout<<"this vertex have no edges."<<std::endl;
            }
            else{
                Node *n=adgencyList[i];
                while (n!=nullptr)
                {
                    std::cout<<"vertex number: "<<n->id<<" and the weight is: "<<n->weight<<std::endl;
                    n=n->next;
                }
            }
        }
    }
}