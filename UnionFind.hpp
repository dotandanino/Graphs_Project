//dotandanino@gmail.com
#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <iostream>
namespace graph{
    class UnionFind
    {
    private:
        int* parent;
        int size;
    public:
        UnionFind(int numOfVertex);
        ~UnionFind();
        int find(int num) const;
        void myUnion(int num1,int num2);
    };
}
#endif