#ifndef PQTREE
#define PQTREE

#include <vector>

#include "pqnode.h"

using namespace std;

template <typename T> class PQTree {

  public:
    PQTree(const vector<T> &universe);

    void reduce(const vector<T> &constraints);
};


#endif