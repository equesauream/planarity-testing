#include "pqtree.h"
#include "pqnode.h"

using namespace std;

template <typename T> PQTree::PQTree(const vector<T>& universe) {
    for (const auto& element : universe) {
        leaves.push_back(&element);
    }
    
}

