#ifndef PQNODE
#define PQNODE

#include <vector>
#include "pqtree.h"

using namespace std;

enum PQNode_types {leaf, pnode, qnode};

class PQNode {
public:
    PQNode_types type;
    PQTree subtree;

  // the value of a pnode or qnode is 0
    int value;
};


#endif