#ifndef PQNODE
#define PQNODE

#include <vector>
using namespace std;

enum PQNode_types  {leaf, pnode, qnode};

template <typename T> class PQNode
{
  public:
    PQNode_types type;
    T value; // if this is a leaf node
    PQNode<T>* parent;
    vector<PQNode<T>*> children;
    bool blocked;

// constructors
    PQNode(PQNode_types type);
};

#include "pqnode.tpp"

#endif