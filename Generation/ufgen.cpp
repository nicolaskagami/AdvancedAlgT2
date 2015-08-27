

#include<cassert>
#include<iostream>
#include<cstdlib>


int main(int argc, char ** argv)
{
    assert(argc == 3);
    unsigned vertNum = atoi(argv[1]);
    unsigned edgeNum = atoi(argv[2]);
    //printf("Verts:%d\nEdges: %d\n",vertNum,edgeNum);
    srand (time(NULL));
    for(int i=0;i<vertNum;i++)
    {
        std::cout << "make-set " << i << std::endl;
    }
    for(int i=0;i<edgeNum;i++)
    {
        unsigned a,b;
        a = rand() % vertNum;
        b = rand() % vertNum;
        std::cout << "union " << a << " " << b << std::endl;
    }
}
