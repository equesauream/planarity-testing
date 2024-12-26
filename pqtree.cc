#include "pqnode.h"
#include "pqtree.h"

using namespace std;

PQTree::PQTree(const vector<T>& universe) {
    for (const auto& element : universe) {
        leaves.push_back(&element);
    }
    leafCount = leaves.size();
    
}

