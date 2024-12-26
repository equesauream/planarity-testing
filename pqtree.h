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
    const vector<T*> leaves;

  public:
// constructors
    PQTree(const vector<T>& universe) {
        for (const auto& element : universe) {
            leaves.push_back(&element);
        }
    }

// methods
    void reduce(constraint& constraints);
};


#endif