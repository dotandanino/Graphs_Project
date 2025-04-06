//dotandanino@gmail.com
#include "UnionFind.hpp"
using namespace graph;
UnionFind::UnionFind(int numOfVertex)
{
    if(numOfVertex<=0){
        throw std::invalid_argument("num of vertex must be positive number");
    }
    this->size=numOfVertex;
    this->parent=new int[size];
    for(int i=0;i<size;i++){
        parent[i]=i;
    }
}
UnionFind::~UnionFind()
{
    delete[] parent;
}
int UnionFind::find(int num){
    if(num>=size || num<0){
        throw std::invalid_argument("there is no such number in the union");
    }
    while(num!=parent[num]){
        num=parent[num];
    }
    return num;
}
void UnionFind::myUnion(int num1,int num2){
    if(num1>=size || num1<0 || num2>=size || num2<0){
        throw std::invalid_argument("there is no such number in the union");
    }
    int u1=find(num1);
    int u2=find(num2);
    parent[u2]=u1;
}