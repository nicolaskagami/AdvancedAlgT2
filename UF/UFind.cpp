
#include "UFind.h"

UnionFind::UnionFind()
{
   sets = (unsigned*) malloc(INITIAL_SIZE*sizeof(unsigned)); 
   ids = (unsigned*) malloc(INITIAL_SIZE*sizeof(unsigned)); 
   capacity = INITIAL_SIZE;
   occupation = 0;
}
UnionFind::UnionFind(unsigned size)
{
   sets = (unsigned*) malloc(size*sizeof(unsigned)); 
   ids = (unsigned*) malloc(size*sizeof(unsigned)); 
   capacity = size;
   occupation = 0;
}
UnionFind::~UnionFind()
{
    free(sets);
    free(ids);
}
unsigned UnionFind::resize(unsigned newSize)
{
    sets = (unsigned*) realloc(sets,newSize*sizeof(unsigned));
    ids = (unsigned*) realloc(ids,newSize*sizeof(unsigned));
    capacity=newSize;
    if((sets != NULL)||(ids != NULL))
        return 0;
    else
        return 1;
}
void UnionFind::make_set(unsigned set)
{
    if((occupation-1)>=capacity)
    {
        if(resize(capacity*2)!=0)
        {
            std::cerr << "Union Find: Memory Allocation Problem" << std::endl;
            exit(1);
        }
    }
    ids[occupation]=set;
    sets[occupation]=occupation;
    occupation++;
}
unsigned UnionFind::find(unsigned element)
{
    for(unsigned i=0;i<occupation;i++)
    {
        if(ids[i]==element)
        {
            while((i<occupation)&&(sets[i]!=i))
                i=sets[i];
            return i;
        }
    }
    return -1;
}
bool UnionFind::connected(unsigned a, unsigned b)
{
    return(find(a) == find(b));
}
void UnionFind::link(unsigned a, unsigned b)
{
    unsigned aroot = find(a);
    unsigned broot = find(b);
    printf("Linking %d(%d) - %d(%d)\n",a,ids[aroot],b, ids[broot]);
    if((aroot!=-1)&&(broot!=-1))
        sets[aroot]=sets[broot];
}
void UnionFind::print()
{
    printf("Union Find %d/%d\n",occupation,capacity);
    for(unsigned i=0;i<occupation;i++)
    {
        printf("(%d,%d)",ids[i],sets[i]);
    }
    printf("\n");
}
