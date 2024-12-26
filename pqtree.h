#ifndef PQTREE
#define PQTREE

#include <vector>

#include "pqnode.h"

using namespace std;


class PQTree {
    struct constraint {
        int a, b;
    };
    vector<PQNode> children;

  public:
    void reduce(vector<constraint> constraints);
};

#endif