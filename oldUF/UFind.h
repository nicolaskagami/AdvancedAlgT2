#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>
#define INITIAL_SIZE 32

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
    private:
        unsigned * ids;
        unsigned * sets;
        unsigned occupation;
        unsigned capacity;
};
