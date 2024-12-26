#ifndef PQTREE
#define PQTREE

#include <vector>

#include "pqnode.h"

using namespace std;

template <typename T>
class PQTree {
  public:
    vector<PQNode<T>*> leaves;
    PQNode<T>* root;
// constructors
    PQTree(const vector<T>& universe);

// methods
    void reduce(const vector<T> &elements);
};

#include "pqtree.tpp"
#endif