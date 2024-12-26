#include "pqtree.h"
#include "pqnode.h"
#include <iostream>

using namespace std;

template <typename T>
PQTree<T>::PQTree(const vector<T>& universe) {
    for (const auto& element : universe) {
        PQNode<T>* e = new PQNode(element);
        leaves.push_back(e);
    }
}

template <typename T>
void PQTree<T>::reduce(const vector<T> &elements){
    // TODO
}

//for debug printing
template <typename T>
ostream& operator<<(std::ostream& out, const PQTree<T>& t){
    out << "PQTree: ";
    for (const auto& e: t.leaves){
        out << *e << ", ";
    }
    return out;
}
