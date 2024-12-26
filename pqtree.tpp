#include "pqtree.h"
#include "pqnode.h"

using namespace std;

template <typename T> 
PQTree<T>::PQTree(const vector<T>& universe) {
    
    PQNode* _root = new PQNode(pnode);
    _root->parent = nullptr;
    // set up leaf nodes for each element
    for (const auto& element : universe) {
        PQNode* _leaf = new PQNode(leaf);
        _leaf->value = element;
        _leaf->parent = root;
        
        _root->children.push_back(_leaf);

        // the PQTree will track all of the leaves
        leaves.push_back(_leaf);
    }
    root = _root;
}

template <typename T>
PQTree<T>::~PQTree() {
    delete this->root;
}

