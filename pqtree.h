#ifndef PQTREE
#define PQTREE

#include <vector>

#include "pqnode.h"

using namespace std;

template <typename T>
class PQTree {
  public:
    vector<PQNode<T>*> leaves;
    PQNode<T>* root = nullptr;
// constructors
    // by default, the starting node in a PQ tree is a pnode
    PQTree(const vector<T>& universe);
    ~PQTree();

// methods
    void reduce(const vector<T> &elements);
};

#include "pqtree.tpp"
#endif