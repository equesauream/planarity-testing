#ifndef PQNODE
#define PQNODE

enum PQNode_types  {leaf, pnode, qnode};

class my_class
{
public:
    PQNode_types type;
    int value;
};


#endif