#ifndef PQNODE
#define PQNODE

#include <vector>
using namespace std;

enum PQNode_types  {leaf, pnode, qnode};

template <typename T> class PQNode
{
public:
    PQNode_types type;
    T value;
    PQNode<T>* parent;
    vector<PQNode<T>*> children;
    bool blocked;
};

#endif