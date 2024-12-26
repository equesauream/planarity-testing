#ifndef PQTREE
#define PQTREE

#include <vector>

#include "pqnode.h"

using namespace std;

template <typename T>class PQTree {
    struct constraint {
        const vector<T> elements;
        int size;
    };
    vector<T*> leaves;
    int leafCount;

    PQNode<T>* root;

  public:
// constructors
    PQTree(const vector<T>& universe);
    PQTree() {};

// methods
    void reduce(constraint& constraints);
};


#endif