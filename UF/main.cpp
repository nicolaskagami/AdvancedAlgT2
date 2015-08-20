
#include<iostream>
#include "UFind.h"


int main(int argc, char **argv)
{
    UnionFind uf(1);
    for(int i=1;i<17;i++)
        uf.make_set(i);
    uf.link(2,3);
    uf.print();
    uf.link(1,2);
    uf.print();
    uf.link(3,4);
    uf.print();
}
