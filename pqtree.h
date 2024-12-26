#ifndef PQTREE
#define PQTREE

#include <vector>

#include "pqnode.h"

using namespace std;

template <typename T>
class PQTree {
    struct constraint {
        const vector<T> elements;
        int size;
    };
    vector<T*> leaves;

    PQNode<T>* root;

  public:
// constructors
    // by default, the starting node in a PQ tree is a pnode
    PQTree(const vector<T>& universe);
    ~PQTree();

// methods
    void reduce(constraint& constraints);
};

#include "pqtree.tpp"
#endif