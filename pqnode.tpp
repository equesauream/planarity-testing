#include <vector>
#include <iostream>
#include "pqnode.h"

using namespace std;

template <typename T>
PQNode<T>::PQNode(PQNode_types _type){
    type = _type;
}

template <typename T>
PQNode<T>::PQNode(const T &_value){
    type = leaf;
    value = _value;
}

//for debug printing
template <typename T>
ostream& operator<<(std::ostream& out, const PQNode<T>& node){
    if(node.type == leaf){
        out << "Leaf: " << node.value;
    }
    else if(node.type == pnode){
        out << "P node";
    }
    else{
        out << "Q node";
    }
    return out;
}