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
    bool reduction(const vector<T> &elements);

  private:
    bool bubble(const vector<PQNode<T>*> &leaves_to_reduce);
    bool reduce(const vector<PQNode<T>*> &leaves_to_reduce);
};

#include "pqtree.tpp"
#endif