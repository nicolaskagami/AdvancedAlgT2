#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>
#define INITIAL_SIZE 32

#ifndef PATH_COMPRESSION 
#define PATH_COMPRESSION 0
#endif

#ifndef WEIGHT_BALANCING 
#define WEIGHT_BALANCING 0
#endif

class UnionFind
{
    public:
        UnionFind();
        UnionFind(std::istream& in);
        UnionFind(unsigned size);
        ~UnionFind();
        void make_set(unsigned set);
        unsigned find(unsigned element);
        bool connected(unsigned a, unsigned b);
        unsigned resize(unsigned newSize);
        void link(unsigned a, unsigned b);
        void print();
        unsigned biggestRoot();

        unsigned pathCost;
        unsigned numSets;
        unsigned numLinks;
    private:
        unsigned * sets;
        unsigned * weights;
        unsigned capacity;
};
