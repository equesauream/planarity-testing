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
    template <typename T> PQTree(const vector<T>& universe);

// methods
    void reduce(constraint& constraints);
};


#include "pqtree.tpp"
#endif