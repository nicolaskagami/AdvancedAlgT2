
#include "UFind.h"


UnionFind::UnionFind()
{
    pathCost = 0;
    numSets = 0;
    numLinks = 0;
    sets = (unsigned*) malloc(INITIAL_SIZE*sizeof(unsigned)); 
    weights = (unsigned*) malloc(INITIAL_SIZE*sizeof(unsigned)); 
    capacity = INITIAL_SIZE;
}
UnionFind::UnionFind(std::istream& in)
{
    pathCost = 0;
    numSets = 0;
    numLinks = 0;
    sets = (unsigned*) malloc(INITIAL_SIZE*sizeof(unsigned)); 
    weights = (unsigned*) malloc(INITIAL_SIZE*sizeof(unsigned)); 
    capacity = INITIAL_SIZE;
    std::string line;
    unsigned a,b;
    char ac;

    while(std::getline(in,line))
    {
        if(line.substr(0,8)=="make-set")
        {
            std::stringstream arc(line);
            arc.seekg(8);
            arc >> a;
            //std::cout << "making set " << a << std::endl; 
            make_set(a);
        }
        if(line.substr(0,5)=="union")
        {
            std::stringstream arc(line);
            arc.seekg(5);
            arc >> a >> b;
            //std::cout << "union " << a << " " << b << std::endl; 
            link(a,b);
        }
        if(line.substr(0,4)=="find")
        {
            std::stringstream arc(line);
            arc.seekg(4);
            arc >> a;
            std::cout << find(a) << std::endl; 
        }
    }
}
UnionFind::UnionFind(unsigned size)
{
    pathCost = 0;
    numSets = 0;
    numLinks = 0;
    sets = (unsigned*) malloc(size*sizeof(unsigned)); 
    weights = (unsigned*) malloc(size*sizeof(unsigned)); 
    capacity = size;
}
UnionFind::~UnionFind()
{
    free(sets);
    free(weights);
}
unsigned UnionFind::resize(unsigned newSize)
{
    unsigned oldSize = capacity;
    sets = (unsigned*) realloc(sets,newSize*sizeof(unsigned));
    weights = (unsigned*) realloc(weights,newSize*sizeof(unsigned));
    for (unsigned i=oldSize;i<newSize;i++)
        weights[i] = 0;
    capacity=newSize;
    if(sets != NULL)
        return 0;
    else
        return 1;
}
void UnionFind::make_set(unsigned set)
{
    numSets++;
    if(set>=(capacity-1))
    {
        if(set>(capacity*2))
        {
            if(resize(set)!=0)
            {
                std::cerr << "Union Find: Memory Allocation Problem" << std::endl;
                exit(1);
            }
        }
        else
        {
            if(resize(capacity*2)!=0)
            {
                std::cerr << "Union Find: Memory Allocation Problem" << std::endl;
                exit(1);
            }
        }
    }
    sets[set]=set;
    weights[set]=1;
}
unsigned UnionFind::find(unsigned element)
{
    unsigned i = element;
    if(weights[element]>0)
    {
        while((i<capacity)&&(sets[i]!=i))
        {
            pathCost++;
            i=sets[i];
        }
        if(PATH_COMPRESSION)
            sets[element]=i;//Path Compression
        return i;
    }
    return -1;
}
bool UnionFind::connected(unsigned a, unsigned b)
{
    return(find(a) == find(b));
}
void UnionFind::link(unsigned a, unsigned b)
{
    numLinks++;
    unsigned aroot = find(a);
    unsigned broot = find(b);
    //printf("Linking %d(%d) - %d(%d)\n",a,ids[aroot],b, ids[broot]);
    if((aroot!=-1)&&(broot!=-1)&&(aroot!=broot))
    {
        if(WEIGHT_BALANCING)
        {
            if(weights[aroot]>weights[broot])//Weight Balancing
            {
                weights[aroot]+=weights[broot];
                sets[broot]=sets[aroot];
            }
            else
            {
                weights[broot]+=weights[aroot];
                sets[aroot]=sets[broot];
            }
        }
        else
        {
            weights[aroot]+=weights[broot];
            sets[broot]=sets[aroot];
        }
    }
}
void UnionFind::print()
{
    printf("Union Find %d/%d\n",capacity);
    for(unsigned i=0;i<capacity;i++)
    {
        printf("(%d,%d)",sets[i]);
    }
    printf("\n");
}
unsigned UnionFind::biggestRoot()
{
    unsigned biggest = 0;
    unsigned biggestRoot = 0;
    for(unsigned i=0;i<capacity;i++)
    {
        if(weights[i]>biggest)
        {
            biggest = weights[i]; 
            biggestRoot = i;
        }
    }
    unsigned verify=0;
    for(unsigned i =0;i<capacity;i++)
    {
        if(find(i)==biggestRoot)
        {
            verify++;
        }
    }
    std::cerr << verify << " " << biggest << " " << biggestRoot << std::endl;
    return biggest;
}
