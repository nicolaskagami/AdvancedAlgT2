
#include<iostream>
#include "UFind.h"


int main(int argc, char **argv)
{
    UnionFind uf(std::cin);
    printf("Biggest: %d\n",uf.biggestRoot());
}
