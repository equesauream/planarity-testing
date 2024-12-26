#ifndef PQTREE
#define PQTREE

#include <vector>

#include "pqnode.h"

using namespace std;

template <typename T> class PQTree {
    struct constraint {
        const vector<T> elements;
        int size;
    };

  public:
    PQTree(const vector<T> &universe);

    void reduce(constraint& constraints);
};


#endif