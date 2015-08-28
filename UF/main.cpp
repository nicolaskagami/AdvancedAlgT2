
#include<iostream>
#include "UFind.h"


int main(int argc, char **argv)
{
    UnionFind uf(std::cin);
    std::cout << WEIGHT_BALANCING << " " << PATH_COMPRESSION << " " << uf.numSets << " " << uf.numLinks << " " << uf.biggestRoot() << " " << uf.pathCost << std::endl;
}
